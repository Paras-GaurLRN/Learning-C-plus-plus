#include <iostream>

int main()
{
    int SIZE;
    std::cout << "Enter Array Length : ";
    std::cin >> SIZE;
    std::cout << std::endl;

    int ARRAY[SIZE];
    int makiter = 0;
    while(makiter < SIZE)
    {
        std::cout << "Enter Element at Index " << makiter << " : ";
        std::cin >> ARRAY[makiter];
        std::cout << std::endl;
        makiter++;
    }

    int UNIQUE_ARRAY[SIZE];
    UNIQUE_ARRAY[0] = ARRAY[0];
    int UNIdex = 1;

    for(int iter = 1; iter < SIZE; iter++)
    {
        int elem = ARRAY[iter];
        int uniter = 0;
        for(uniter = 0; uniter < UNIdex; uniter++)
        {
            if(UNIQUE_ARRAY[uniter] == elem){uniter = iter;}
        }
        if(uniter == UNIdex){UNIQUE_ARRAY[UNIdex] = elem; UNIdex += 1;}
    }

    std::cout << "After Removing The Duplicates: " << std::endl;
    for(int looper = 0; looper < UNIdex; looper++)
    {
        std::cout << UNIQUE_ARRAY[looper] << ' ';
    }

    return 0;
}