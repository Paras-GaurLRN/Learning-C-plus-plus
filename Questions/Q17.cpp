#include <iostream>

typedef int Index;

bool isValid(const char ToCheck)
{
    if(('A' <= ToCheck && ToCheck <= 'Z') or ('a' <= ToCheck && ToCheck <= 'z')){return true;}
    else{std::cout << "Enter Valid Input" << std::endl; return false;}
}

int main()
{
    int S1 = 0;
    int S2 = 0;
    do{
    std::cout << "Enter Size Of First Array: ";
    std::cin >> S1;
    std::cout << std::endl;
    }while(S1 <= 0);

    do{
    std::cout << "Enter Size Of Second Array: ";
    std::cin >> S2;
    std::cout << std::endl;
    }while(S2 <= 0);

    char A1[S1];
    char A2[S2];
    char c;

    std::cout << "Enter First Array" << std::endl;
    for(int iter1 = 0; iter1 < S1; iter1++)
    {
    do{
    std::cout << "Enter Element " << iter1 << ": ";
    std::cin >> c;
    std::cout << std::endl;
    }while(!isValid(c));
    A1[iter1] = c;
    }

    std::cout << "Enter Second Array" << std::endl;
    for(int iter2 = 0; iter2 < S2; iter2++)
    {
    do{
    std::cout << "Enter Element " << iter2 << ": ";
    std::cin >> c;
    std::cout << std::endl;
    }while(!isValid(c));
    A2[iter2] = c;
    }

    char A3[S1+S2];

    for(int iter3 = 0; iter3 < (S1 + S2); iter3++)
    {
        if(iter3 < S1){A3[iter3] = A1[iter3];}
        else{A3[iter3] = A2[iter3 - S1];}
    }

    std::cout << "New Ordered Array is as follows: " << std::endl;
    for(int iter4 = 0; iter4 < (S1 + S2); iter4++)
    {
        std::cout << "Element At " << iter4 << ": " << A3[iter4] << std::endl;
    }

    return 0;
}