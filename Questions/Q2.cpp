#include <iostream>

int main()
{
    double x,y,z;
    
    std::cout << "Enter 3 Numbers: ";
    std::cin >> x >> y >> z;
    std::cout << std::endl;

    double largest = x;
    if(y > largest){largest = y;}
    if(z > largest){largest = z;}

    std::cout << "Largest = " << largest << std::endl;
    return 0;
}