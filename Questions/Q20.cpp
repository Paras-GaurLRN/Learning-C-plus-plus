#include <iostream>
#include <optional>
#include <cmath>

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

    bool operator!=(const Matrix& B) const {return !(*this==B);}

    std::optional<double> det()
    {
        if (__R != __C) {return std::nullopt;}

        int n = __R;
        if(n == 1){return pMatrix[0];}

        double** A = new double*[n];
        for (int i = 0; i < n; ++i)
        {
            A[i] = new double[n];
            for (int j = 0; j < n; ++j)
            {
                A[i][j] = static_cast<double>(pMatrix[i * __C + j]);
            }
        }

        double det = 1.0;
        int sign = 1;

        for (int i = 0; i < n; ++i)
        {// Finding pivot row
            int pivot = i;
            for (int r = i + 1; r < n; ++r)
            {
                if (fabs(A[r][i]) > fabs(A[pivot][i]))
                    pivot = r;
            }

            if (fabs(A[pivot][i]) < 1e-12)
            {
                det = 0.0;
                break;
            }

        // Swapping rows if needed
            if (pivot != i)
            {
                for (int c = 0; c < n; ++c)
                {
                    double temp = A[i][c];
                    A[i][c] = A[pivot][c];
                    A[pivot][c] = temp;
                }
                sign *= -1;
            }

            det *= A[i][i];

        // Eliminating factors below
            for (int r = i + 1; r < n; ++r)
            {
                double factor = A[r][i] / A[i][i];
                for (int c = i; c < n; ++c)
                {
                    A[r][c] -= factor * A[i][c];
                }
            }
        }

        // Cleanup
        for (int i = 0; i < n; ++i)
            delete[] A[i];
        delete[] A;

        return det * sign;
    }
};

int main()
{
    std::cout << "For Matrix 1: " << std::endl;
    Matrix Mtx(std::nullopt,std::nullopt);
    
    std::optional<double> determinant = Mtx.det();
    if(determinant.has_value()){std::cout << "The Determinant Of The Matrix is: " << determinant.value();}
    else{std::cout << "The Determinant is Not Defined For A Non-Square Matrix!";}
    std::cout << std::endl;

    return 0;
}