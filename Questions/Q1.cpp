#include <iostream>
#include <math.h>

bool isValid(int x, int y){return (x > 0) and (y > 0);}

int GCD_recursion_base(int x, int y)
{
// x >= y needed

    if(y==0){return x;}
    else{return GCD_recursion_base(y, x % y);}
}

int GCD_recursion(int x, int y)
{
    if(!isValid(x,y)){return -1;}
    else{return GCD_recursion_base((int)fmax(x,y), (int)fmin(x,y));}
}

int GCD_loop(int x, int y)
{
    if(!isValid(x,y)){return -1;}

    int a,b;
    a = (int)fmax(x,y);
    b = (int)fmin(x,y);

    int t;
    while(b!=0)
    {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main()
{
    int a, b, gcd;
    char ans;

    std::cout << "### Welcome To GCD Finder ###" << '\n' << "Enter 2 Numbers: ";
    std::cin >> a >> b;
    std::cout << std::endl;

    do
    {
    std::cout<< "Do You Want Recursion (Y/N)? \n-> ";
    std::cin >> ans;
    std::cout << std::endl;
    }
    while(ans != 'Y' and ans != 'N');

    if(ans == 'Y'){gcd = GCD_recursion(a,b);}
    else{gcd = GCD_loop(a,b);}

    if(gcd == -1){std::cout << "Wrong Inputs!" << std::endl;}
    else{std::cout << "The GCD = " << gcd << std::endl;}
    return 0;
}