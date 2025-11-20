#include <iostream>

#define pass do{}while(0)

int main()
{
    int x ;
    std::cout << "Enter Number : ";
    std::cin >> x;
    std::cout << std::endl;

    std::string strform = std::to_string(x);
    int len = strform.length() - 1;
    if(len == 0){pass;}
    else
    {
    char temp = strform[0];
    strform[0] = strform[len];
    strform[len] = temp;
    }

    std::cout << "New Number = " << strform << std::endl;
    return 0;
}