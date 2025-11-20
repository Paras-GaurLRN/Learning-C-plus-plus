#include <iostream>

int main()
{
    int x ;
    std::cout << "Enter Number : ";
    std::cin >> x;
    std::cout << std::endl;

    std::string strform = std::to_string(x);
    int len = strform.length();
    
    short Sum = 0;
    if(len == 1){Sum = (short)x;}
    else{Sum = (short)(strform[0] - '0') + (short)(strform[len - 1] - '0');}

    std::cout << "Sum = " << Sum << std::endl;
    return 0;
}