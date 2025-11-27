#include <iostream>
#include <optional>

typedef unsigned int Index;

class Matrix
{
    private:
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

    public:
    Matrix(std::optional<int> R, std::optional<int> C)
    {
        if(R.has_value() and C.has_value()){__R = R.value(); __C = C.value();}
        else
        {
        std::cout << "Enter Number Of Rows: "; std::cin >> __R; std::cout << std::endl;
        std::cout << "Enter Number Of Columns: "; std::cin >> __C; std::cout << std::endl;
        }
        pMatrix = new int[__R * __C];
        Populate();
    }

    ~Matrix(){delete[] pMatrix;}

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
};

int main()
{
    std::cout << "Enter Matrix: " << std::endl;
    Matrix Mtx(std::nullopt,std::nullopt);

    char c;
    do{
    std::cout << "Do You Want To Sum a Row or a Column (R/C)?\n-> ";
    std::cin >> c; std::cout << std::endl;
    }while(c != 'R' and c != 'C');

    std::optional<int> SUM = 0;
    int Entry_Number = 0;
    if(c == 'R')
    {
        do{
        std::cout << "Enter The Number Of The Row: ";
        std::cin >> Entry_Number;
        SUM = Mtx.Row_Sum(Entry_Number);}while(!SUM.has_value());
        std::cout << "The Sum Of The Row: " << SUM.value() << std::endl;
    }
    else
    {
        do{
        std::cout << "Enter The Number Of The Column: ";
        std::cin >> Entry_Number;
        SUM = Mtx.Column_Sum(Entry_Number);}while(!SUM.has_value());
        std::cout << "The Sum Of The Column: " << SUM.value() << std::endl;
    }

    return 0;
}