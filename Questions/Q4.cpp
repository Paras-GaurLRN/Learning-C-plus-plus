#include <iostream>

int main()
{
    int x ;
    std::cout << "Enter Number : ";
    std::cin >> x;
    std::cout << std::endl;

    std::string strform = std::to_string(x);

    int product = 1;
    for(int _ = 0; strform[_]; _++)
    {
        product *= (int)((char)strform[_] - '0');
    }
    std::cout << "The Product = " << product << std::endl;
    return 0;
}