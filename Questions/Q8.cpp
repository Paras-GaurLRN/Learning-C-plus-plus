#include <iostream>

int main()
{
    int n;
    std::cout << "Enter Number : ";
    std::cin >> n;
    std::cout << std::endl;
    
    bool oflag;
    char ans = 'P';

    do
    {
        std::cout << "Do You Want Even Numbers Or Odd Numbers till " << n << " ? (E/O)\n-> ";
        std::cin >> ans;
    }while(ans != 'E' and ans != 'O');

    (ans == 'O') ? (oflag = 1):(oflag = 0);

    int sum = 0;
    for(int num = (int)oflag; num <= n; num+=2)
    {
        sum += num;
    }

    std::cout << "Sum = " << sum << std::endl;
    return 0;
}