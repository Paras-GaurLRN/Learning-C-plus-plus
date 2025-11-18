#include <iostream>

int main()
{
    int x ;
    std::cout << "Enter Number : ";
    std::cin >> x;
    std::cout << std::endl;

    std::string strform = std::to_string(x);

    int Sum = 0;
    int iter = strform.length();
    while(iter != 0)
    {
        Sum += (int)((char)(strform[iter-1]) - '0');
        iter-=1;
    }
    std::cout << "Sum = " << Sum << std::endl;
    return 0;
}