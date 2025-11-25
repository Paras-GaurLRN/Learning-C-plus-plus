#include <iostream>

typedef int Index;

template<std::size_t SIZE>
void XOR_Swap(int (&pary)[SIZE], Index a, Index b)
{
    pary[a] = pary[a] ^ pary[b];
    pary[b] = pary[a] ^ pary[b];
    pary[a] = pary[a] ^ pary[b];
}

template<std::size_t SIZE>
void Insertion_Sort(int (&pary)[SIZE])
{
    if(SIZE == 1){return;}

    int current;
    int dummy;
    bool switchflag;
    for(Index idx = 0; idx < SIZE; ++idx)
    {
        current = idx;
        switchflag = false;
        for(Index iter = idx+1; iter < SIZE; ++iter)
        {
            dummy = iter;
            if(pary[dummy] < pary[current])
            {
                current = dummy;
                iter = dummy;
                switchflag = true;
            }
        }
        if(switchflag){XOR_Swap(pary,current,idx);}
    }
}

template<std::size_t SIZE>
Index Binary_Search(int (&pary)[SIZE], int target)
{
    Index L = 0;
    Index R = SIZE - 1;
    while(L <= R)
    {
        Index M = (L + (R - L)/2);
        if(pary[M] < target){L = M + 1;}
        else if(pary[M] > target){R = M - 1;}
        else{return M;}
    }
    return -1;
}

template<std::size_t SIZE>
Index RecBS(int (&pary)[SIZE], Index L, Index R, int target)
{
    if(L > R){return -1;}
    Index M = (L + (R - L)/2);
    if(pary[M] < target){return RecBS<SIZE>(pary,M+1,R,target);}
    else if(pary[M] > target){return RecBS<SIZE>(pary,L,M-1,target);}
    else{return M;}
}

int main()
{
    const std::size_t SIZE = 10;
    std::cout << "The Current Array Size Is-" << SIZE << std::endl;
    std::cout << "To Change The Array Size, Modify The File and Re-execute" << std::endl;

    int Array[SIZE];
    int k;
    for(int iter = 0; iter < SIZE; ++iter)
    {
        std::cout << "Enter Element At Index " << iter << ": ";
        std::cin >> k;
        std::cout << std::endl;
        Array[iter] = k;
    }
    
    Insertion_Sort<SIZE>(Array);

    std::cout << "Sorted Array" << std::endl;
    for(int iter = 0; iter < SIZE; ++iter)
    {
        std::cout << "Element At Index " << iter << ": " << Array[iter] << std::endl;
    }

    char c;
    std::cout << "Do You Want Recursion or Not (Y/N)?\n-> ";
    std::cin >> c;
    std::cout << std::endl;

    int target;
    std::cout << "Enter Value To Find: ";
    std::cin >> target;
    std::cout << std::endl;

    Index position;
    if(c == 'Y'){position = RecBS<SIZE>(Array,0,SIZE-1,target);}
    else{position = Binary_Search<SIZE>(Array,target);}

    if(position == -1){std::cout << target << " is Not In The Array!" << std::endl;}
    else{std::cout << target << " is In Sorted Array at Index: " << position << std::endl;}

    return 0;
}