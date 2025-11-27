#include <iostream>
#include <optional>
#include <limits>
#include <math.h>

typedef unsigned int Index;

class Matrix
{
    private:
    static int count;
    typedef unsigned int __Entry_Size;
    __Entry_Size __R;
    __Entry_Size __C;
    int* pMatrix;

    void Populate()
    {
        std::cout << "Dimension of Matrix is " << __R << " x " << __C << std::endl;
        for(Index Riter = 0; Riter < __R; ++Riter)
        {
        for(Index Citer = 0; Citer < __C; ++Citer)
        {
            std::cout << "Enter Value At Index ("<<(Riter+1)<<','<<(Citer+1)<<"): ";
            std::cin >> pMatrix[Riter*__C + Citer]; std::cout << std::endl;
        }
        }
        std::cout << "Matrix Successfully Populated!" << std::endl;
    }

    void Populate(int val)
    {
        for(Index Riter = 0; Riter < __R; ++Riter)
        {
        for(Index Citer = 0; Citer < __C; ++Citer)
        {
            pMatrix[Riter*__C + Citer] = val;
        }
        }
    }

    public:
    ~Matrix(){delete[] pMatrix; --count;}

    Matrix(std::optional<int> R = std::nullopt, std::optional<int> C = std::nullopt)
    {
        count+=1;
        if(R.has_value() and C.has_value()){__R = R.value(); __C = C.value();}
        else
        {
        std::cout << "Enter Number Of Rows: "; std::cin >> __R; std::cout << std::endl;
        std::cout << "Enter Number Of Columns: "; std::cin >> __C; std::cout << std::endl;
        }
        pMatrix = new int[__R * __C];
        Populate();
    }

    Matrix(int val , std::optional<int> R = std::nullopt, std::optional<int> C = std::nullopt)
    {
        count+=1;
        if(R.has_value() and C.has_value()){__R = R.value(); __C = C.value();}
        else
        {
        std::cout << "Enter Number Of Rows: "; std::cin >> __R; std::cout << std::endl;
        std::cout << "Enter Number Of Columns: "; std::cin >> __C; std::cout << std::endl;
        }
        pMatrix = new int[__R * __C];
        Populate(val);
    }

    void RePopulate()
    {
        delete[] pMatrix;
        pMatrix = new int[__R*__C];
        Populate();
    }

    void Visualize() const
    {
        std::cout << "Dimension of Matrix is " << __R << " x " << __C << std::endl;
        for(Index Riter = 0; Riter < __R; ++Riter)
        {
        for(Index Citer = 0; Citer < __C; ++Citer)
        {
            std::cout << "Value At Index ("<<(Riter+1)<<','<<(Citer+1)<<"): ";
            std::cout << pMatrix[Riter*__C + Citer] << std::endl;
        }
        }
        std::cout << std::endl;
    }

    bool operator==(const Matrix& B) const
    {
    if(__R != B.__R or __C != B.__C){return false;}
    for(Index Riter = 0; Riter < __R; ++Riter)
    {
    for(Index Citer = 0; Citer < __C; ++Citer)
    {
        if(pMatrix[Riter*(__C) + Citer] != B.pMatrix[Riter*(B.__C) + Citer]){return false;}
    }
    }
    return true;
    }

    inline bool operator!=(const Matrix& B) const {return !(*this==B);}

    std::optional<int> Row_Sum(int RowNumber)
    {
        if(!((0 < RowNumber) and (RowNumber <= __R))){return std::nullopt;}
        int Sum = 0;
        for(Index iter = 0; iter < __C; ++iter)
        {
            Sum += pMatrix[(RowNumber - 1)*__C + iter];
        }
        return Sum;
    }

    std::optional<int> Column_Sum(int ColumnNumber)
    {
        if(!((0 < ColumnNumber) and (ColumnNumber <= __C))){return std::nullopt;}
        int Sum = 0;
        for(Index iter = 0; iter < __R; ++iter)
        {
            Sum += pMatrix[__C*iter + ColumnNumber - 1];
        }
        return Sum;
    }

    std::optional<int> Trace()
    {
        if(__R != __C){return std::nullopt;}
        int value = 0;
        for(Index iter = 0; iter < __R; ++iter)
        {
            value += pMatrix[(iter)*__C + iter];
        }
        return value;
    }

    std::optional<int> offTrace()
    {
        if(__R != __C){return std::nullopt;}
        int leftTrace = 0;
        for(Index iter = 0; iter < __R; iter++)
        {
            leftTrace += pMatrix[(__R -1 - iter)*__C + iter];
        }
        return leftTrace;
    }

    bool isSparse()
    {
        std::cout << "Rule: A Matrix is Sparse if there are atleast same number of Zero Rows";
        int cnt = 0;
        for(Index Riter = 0; Riter < __R; ++Riter)
        {
        for(Index Citer = 0; Citer < __C; ++Citer)
        {
            if(pMatrix[Riter*__C + Citer] == 0){++cnt;}
            else{--cnt;}
        }
        }
        if(cnt > 0){return false;}
        else{return true;}
    }

    bool isIdentity()
    {
        if(__R != __C){return false;}
        for(Index Riter = 0; Riter < __R; ++Riter)
        {
        for(Index Citer = 0; Citer < __C; ++Citer)
        {
            if((Riter == Citer) and (pMatrix[Riter*__C + Citer] != 1)){return false;}
            else if((Riter != Citer) and (pMatrix[Riter*__C + Citer] != 0)){return false;}
        }
        }
        return true;
    }

    Matrix operator+(const Matrix& B) const
    {
        if((this->__C != B.__C) or (this->__R != B.__R))
        {throw std::invalid_argument("Matrix dimensions are incompatible for addition");}
        Matrix result(0,this->__R,this->__C);
        for(Index Riter = 0; Riter < this->__R; ++Riter)
        {
        for(Index Citer = 0; Citer < this->__C; ++Citer)
        {
            result.pMatrix[Riter*(this->__C) + Citer] = pMatrix[Riter*(this->__C) + Citer] + B.pMatrix[Riter*(this->__C) + Citer];
        }
        }
        return result;
    }

    Matrix operator*(const Matrix& B) const
    {
        if(this->__C != B.__R)
        {throw std::invalid_argument("Matrix dimensions are incompatible for multiplication");}
        Matrix result(0,this->__R,B.__C);
        for(Index Riter = 0; Riter < (this->__R); ++Riter)
        {
        for(Index Citer = 0; Citer < B.__C; ++Citer)
        {
        for(Index k = 0; k < (this->__C); ++k)
        {
            result.pMatrix[(B.__C)*Riter + Citer] += pMatrix[Riter*(this->__C) + k] * B.pMatrix[(B.__C)*k + Citer];
        }
        }
        }

        return result;
    }

    Matrix operator!() const
    {
        Matrix result(0,this->__C,this->__R);
        for(Index Riter = 0; Riter < __R; ++Riter)
        {
        for(Index Citer = 0; Citer < __C; ++Citer)
        {
            result.pMatrix[Citer*__R + Riter] = this->pMatrix[Riter*__C + Citer];
        }
        }
        return result;
    }
};

int Matrix::count = 0;

short Menu()
{
std::cout << "### Welcome To The Matrix Manupulator ###" << std::endl;
short opp_type = -1;
while(1)
{
TXT_PROMPT:
    std::cout << "Please Choose An Operation:\n1) Add Matrices\n2) Multiply 2 Matrices\n";
    std::cout << "3) Transpose Of A Matrix\n0) Exit\n(0/1/2/3) -> ";
    std::cin >> opp_type; std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if(opp_type != 0 and opp_type != 1 and opp_type != 2 and opp_type != 3)
    {std::cout << "Please Enter Valid Input!\n"; goto TXT_PROMPT;}

OPERATIONS:
    switch(opp_type)
    {
    case 0:
        std::cout << "Exiting Program!"; return 0;
    case 1:
    {
        std::cout << "First Matrix: ";
        Matrix M1(std::nullopt,std::nullopt);
        std::cout << "Second Matrix: ";
        Matrix M2(std::nullopt,std::nullopt);
        (M1 + M2).Visualize();
        break;
    }
    case 2:
    {
        std::cout << "First Matrix: ";
        Matrix M1(std::nullopt,std::nullopt);
        std::cout << "Second Matrix: ";
        Matrix M2(std::nullopt,std::nullopt);
        (M1 * M2).Visualize();
        break;
    }
    case 3:
    {
    std::cout << "Matrix: ";
    Matrix M(std::nullopt, std::nullopt);
    (!M).Visualize();
    break;
    }
    }
}
}

int main()
{
    try { Menu(); }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}