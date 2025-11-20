#include <iostream>
#include <math.h>

int main()
{
    int n;
    std::cout << "### Welcome To Sum Of Squares ###\nEnter Number : ";
    std::cin >> n;
    std::cout << std::endl;

    long Sum = 0;
    for(int i = 1; i <= n; i++)
    {
        Sum += (long)(powf(i,2));
    }

    std::cout << "The Sum = " << Sum << std::endl;
    return 0;
}