#include <iostream>
#define SIZE 5

int LIST[SIZE];

void read(int (&ARRAY)[SIZE]);

void display(int (&ARRAY)[SIZE]);

void sort(int (&ARRAY)[SIZE]);

void swap(int& A, int& B);

int main()
{
    read(LIST);
    display(LIST);
    sort(LIST);
    display(LIST);
    return 0;
}

void read(int (&ARRAY)[SIZE])
{
    for(int &I : ARRAY)
    {
        std::cout << "Enter Element: ";
        std::cin >> I;
    }
    std::cout << std::endl;
}

void display(int (&ARRAY)[SIZE])
{
    for(const int &I : ARRAY) {std::cout << I << '\n';}
    std::cout << std::endl;
}

void sort(int (&ARRAY)[SIZE])
{
    std::cout << "Sorting Now" << '\n' << std::endl;
    for(int iter = 0; iter < SIZE; ++iter)
    {
    for(int inner_iter = iter + 1; inner_iter < SIZE; ++inner_iter)
    {
    if(ARRAY[iter] > ARRAY[inner_iter]){swap(ARRAY[iter],ARRAY[inner_iter]);}
    }
    }
}

void swap(int& A, int& B)
{A = A ^ B; B = A ^ B; A = A ^ B;}