#include <iostream>
#include <string>

#define pass do{}while(0)

int main()
{
    int x;
    std::cout << "Enter Number : ";
    std::cin >> x;
    std::cout << std::endl;

    std::string pali = std::to_string(x);

    int len = pali.length();
    for(int iter = 0; iter < len ; iter++)
    {
        if(pali[iter] == pali[len - iter - 1])
        {
            pass;
        }
        else
        {
            std::cout << "The Number is not a Palindrome!" << std::endl;
            return 0;
        }
    }
    std::cout << "The Number is a Palindrome!" << std::endl;
    return 0;
}