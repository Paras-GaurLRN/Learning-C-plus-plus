#include <iostream>

int main()
{
    int x ;
    std::cout << "Enter Number : ";
    std::cin >> x;
    std::cout << std::endl;

    std::string strform = std::to_string(x);

    std::cout << "Reverse :- ";
    int iter = strform.length();
    while(iter != -1)
    {
        std::cout << strform[iter];
        iter-=1;
    }
    std::cout << std::endl;
    return 0;
}