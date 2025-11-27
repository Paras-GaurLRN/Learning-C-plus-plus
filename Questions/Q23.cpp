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
};

int main()
{
    std::cout << "Enter Matrix: " << std::endl;
    Matrix Mtx(std::nullopt,std::nullopt);

    std::optional<int> OT = Mtx.offTrace();
    if(OT.has_value()){std::cout << "The Sum Of The Opposite Diagonal's Element Is: " << OT.value() << std::endl;}
    else{std::cout << "The Operation Is Not Defined For A Non-Square Matrix!" << std::endl;}

    return 0;
}