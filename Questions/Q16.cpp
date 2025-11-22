#include <iostream>
#include <math.h>

#define pass do{}while(0)

typedef int Index;

bool isValid(const std::string ToCheck)
{
    Index idx = 0;
    while(ToCheck[idx])
    {
        if(('A' <= ToCheck[idx] && ToCheck[idx] <= 'Z') or ('a' <= ToCheck[idx] && ToCheck[idx] <= 'z')){pass;}
        else{std::cout << "Enter Valid Input" << std::endl; return false;}
        idx++;
    }
    return true;
}

int STRING_LENGTH(std::string ISTR)
{
    char* pchar = &ISTR[0];
    int counter = 1;
    while(*(pchar + counter)){counter++;}
    return counter;
}

int main()
{
    std::string ASTR, BSTR;
    do{
    std::cout << "Enter String To Insert Into: ";
    std::cin >> ASTR;
    }while(!isValid(ASTR));
    std::cout << std::endl;
    do{
    std::cout << "Enter String To Insert: ";
    std::cin >> BSTR;
    }while(!isValid(BSTR));
    std::cout << std::endl;

    int lenA = STRING_LENGTH(ASTR);
    int lenB = STRING_LENGTH(BSTR);
    int pos;
    do{
    std::cout << "Enter Position To Enter At (Example: 2 for 2nd Position): ";
    std::cin >> pos;
    }while(pos <= 0 or pos > lenA + 1);

    std::string RSTR(lenA + lenB,'\0');
    Index target_index = pos - 1;
    Index insert_index = static_cast<Index>(fminf(pos,lenA)) - 1;
    Index leftover_initiation_index = lenB + insert_index;

    for(Index iter1 = 0; iter1 < insert_index; ++iter1)
    {RSTR[iter1] = ASTR[iter1];}

    for(Index iter2 = 0; iter2 < lenB; ++iter2)
    {RSTR[insert_index+iter2] = BSTR[iter2];}

    for(Index iter3 = 0; iter3 < (lenA-target_index); ++iter3)
    {RSTR[leftover_initiation_index+iter3] = ASTR[iter3+target_index];}

    std::cout << "The Final String Is- " << RSTR << std::endl;
    return 0;
}