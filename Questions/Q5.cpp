#include <iostream>
#include <math.h>

#define pass do{}while(0)

int main()
{
    int x;
    std::cout << "Enter Number : ";
    std::cin >> x;
    std::cout << std::endl;

    // Sieve of Erastosthenes to make a marking array acc to index.
    // index = prime - 1
    int mark[x]; mark[0] = -1;
    for(int _ = 1; _ < x; _++){mark[_] = 0;}

    for(int iter = 1; iter <= x; iter++)
    {
        if(mark[iter] == -1){pass;}
        else if(mark[iter] == 0)
        {
            mark[iter] = 1;
            for(int marker = 2*iter + 1; marker < x; marker+=iter+1)
            {
                mark[marker] = -1;
            }
        }
    }

    // Going through the sieve and seeing if the prime devides the number
    std::cout << "The Prime Factors of " << x << " are :-" << std::endl;
    int prime_index = 1;
    int last_prime = 1;
    while(mark[prime_index])
    {
        if(prime_index + 1 > (x/last_prime)){break;}
        // number/last_prime is an updating bound upper and makes the algo much faster
        if(x % (prime_index + 1) == 0)
        {
            std::cout << " " << (prime_index+1); last_prime = prime_index + 1;
        }

        int k = 1;
        while(k != 0)
        {
            if(mark[prime_index + k] == 1){prime_index += k; k = 0;}
            else{k += 1;}
        }
    }
    
    std::cout << std::endl;
    return 0;
}