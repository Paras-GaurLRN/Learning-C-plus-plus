#include <iostream>

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

void ADDRESS_FINDER(std::string ISTR)
{
    Index idx = 0;
    short d; 
    short k;
    while(ISTR[idx])
    {
        k = (idx + 1)%100;
        if(k >= 11 and k <= 13){d = 4;}
        else{d = (idx+1)%10;}
        std::cout << "Address Of Character at the " << (idx+1);
        switch(d)
        {
            case 1:
                std::cout << "st"; break;
            case 2:
                std::cout << "nd"; break;
            case 3:
                std::cout << "rd"; break;
            default:
                std::cout << "th";
        }
        std::cout << " Position = " << static_cast<const void*>(&ISTR[idx]) << '\n';
        idx++;
    }
    std::cout << std::endl;
}

int STRING_LENGTH(std::string ISTR)
{
    char* pchar = &ISTR[0];
    int counter = 1;
    while(*(pchar + counter)){counter++;}
    return counter;
}

void WRAPPED_STRING_LENGTH(const std::string ISTR)
{std::cout << "The Length Of The String = " << STRING_LENGTH(ISTR) << std::endl;}

void STRING_REVERSE(const std::string ISTR)
{
    int len, idx;
    len = STRING_LENGTH(ISTR);
    std::string RSTR(len,'\0');
    if(len == 1){RSTR = ISTR;}
    else{
    idx = len-1;
    for(int iter = 0; iter < len; iter++)
    {
        RSTR[iter] = ISTR[idx]; idx--;
    }
    }
    std::cout << "The Reversed String is- " << RSTR << std::endl;
}

std::string STRING_UPPERCASE(const std::string ISTR)
{
    Index idx = 0;
    int len = STRING_LENGTH(ISTR);
    std::string Uppered(len,'\0');
    while(len != 0)
    {
        if('a' <= ISTR[idx] && ISTR[idx] <= 'z'){Uppered[idx] = ISTR[idx] - 32;}
        else{Uppered[idx] = ISTR[idx];}
        idx++; len--;
    }
    return Uppered;
}

void WRAPPED_STRING_UPPERCASE(std::string ISTR)
{std::cout << "The UpperCase String is- " << STRING_UPPERCASE(ISTR) << std::endl;}

void STRING_CONCAT(const std::string _ASTR, const std::string _BSTR)
{
    int lenA = STRING_LENGTH(_ASTR);
    int len = lenA + STRING_LENGTH(_BSTR);
    std::string CSTR(len, '\0');
    for(int iter = 0; iter < len; iter++)
    {
        if(iter < lenA){CSTR[iter] = _ASTR[iter];}
        else{CSTR[iter] = _BSTR[iter - lenA];}
    }
    std::cout << "The Concatinated String is- " << CSTR << std::endl;
}

void STRING_COMP(std::string ASTR, std::string BSTR)
{
    std::string _ASTR, _BSTR;
    
    char k;
    do{
    std::cout << "Case-Sensitive Comparison or Case-Insensitive Comparison (S/I)?\n-> ";
    std::cin >> k;}while(k != 'S' and k != 'I');

    if(k == 'I'){_ASTR = STRING_UPPERCASE(ASTR); _BSTR = STRING_UPPERCASE(BSTR);}
    else{_ASTR = ASTR; _BSTR = BSTR;}

    int lenA = STRING_LENGTH(_ASTR);
    int lenB = STRING_LENGTH(_BSTR);

    if(lenA != lenB){std::cout << "\nThe Strings Are Not Same" << std::endl; return;}
    else
    {
        for(int iter = 0; iter < lenA; iter++)
        {
            if(_ASTR[iter] != _BSTR[iter]){std::cout << "\nThe Strings Are Not Same" << std::endl; return;}
        }
    }
    std::cout << "\nThe Strings Are Same" << std::endl;
}

void OPERATE(short NO_OF_OPERANDS, short OPERATION_TYPE)
{
    std::string STR1;
    switch(NO_OF_OPERANDS)
    {
        case 1:
            do{std::cout << "Please Enter String: "; std::cin >> STR1;}while(!isValid(STR1));
            std::cout << std::endl;
            switch(OPERATION_TYPE)
            {
                case 1:
                    ADDRESS_FINDER(STR1);
                    break;
                case 2:
                    WRAPPED_STRING_LENGTH(STR1);
                    break;
                case 3:
                    STRING_REVERSE(STR1);
                    break;
                case 4:
                    WRAPPED_STRING_UPPERCASE(STR1);
            }
            break;
        case 2:
            std::string STR2;
            do{std::cout << "Please Enter 1st String: "; std::cin >> STR1;}while(!isValid(STR1));
            std::cout << std::endl;
            do{std::cout << "Please Enter 2nd String: "; std::cin >> STR2;}while(!isValid(STR2));
            std::cout << std::endl;
            switch(OPERATION_TYPE)
            {
                case 1:
                    STRING_CONCAT(STR1,STR2);
                    break;
                case 2:
                    STRING_COMP(STR1,STR2);
            }
    }
}

void MENU()
{
    while(1)
    {
        short NO_OF_OPERANDS, OPERATION_TYPE;
        do{
        std::cout << "### Welcome To String Manipulator Module Beta 1 ###" << std::endl;
        std::cout << "Please Choose Number Of Operands or Press 0 To Exit(0/1/2): ";
        std::cin >> NO_OF_OPERANDS;}while(NO_OF_OPERANDS != 0 and NO_OF_OPERANDS != 1 and NO_OF_OPERANDS != 2);
        if(NO_OF_OPERANDS == 0){std::cout << "Exiting System!" << std::endl; return;}
        std::cout << std::endl;
        switch(NO_OF_OPERANDS)
        {
        case 1:
            do{
            std::cout << "Please Choose Operation Type-\n1) Address Finder\n2) String Length\n";
            std::cout << "3) String Reversal\n4) UpperCase Conversion\n(1/2/3/4): ";
            std::cin >> OPERATION_TYPE;}
            while(OPERATION_TYPE != 1 and OPERATION_TYPE != 2 and OPERATION_TYPE!= 3 and OPERATION_TYPE != 4);
            break;
        case 2:
            do{
            std::cout << "Please Choose Operation Type-\n1) String Concatenation\n2) String Comparison\n(1/2): ";
            std::cin >> OPERATION_TYPE;}while(OPERATION_TYPE != 1 and OPERATION_TYPE != 2);
        }
        std::cout << std::endl;
        OPERATE(NO_OF_OPERANDS,OPERATION_TYPE);
    }
}

int main()
{
    MENU();
    return 0;
}

//fix