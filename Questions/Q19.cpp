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

    void Visualize()
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

    friend bool operator==(const Matrix& A, const Matrix& B);
};

bool operator==(const Matrix& A, const Matrix& B)
{
    if(A.__R != B.__R or A.__C != B.__C){return false;}
    for(Index Riter = 0; Riter < A.__R; ++Riter)
    {
    for(Index Citer = 0; Citer < A.__C; ++Citer)
    {
        if(A.pMatrix[Riter*(A.__C) + Citer] != B.pMatrix[Riter*(B.__C) + Citer]){return false;}
    }
    }
    return true;
}

int main()
{
    std::cout << "For Matrix 1: " << std::endl;
    Matrix M1(std::nullopt,std::nullopt);
    std::cout << "For Matrix 2: " << std::endl;
    Matrix M2(std::nullopt,std::nullopt);

    if(M1 == M2){std::cout << "The Matrices Are Equal!";}
    else{std::cout << "The Matrices Are Not Equal!";}
    std::cout << std::endl;

    return 0;
}