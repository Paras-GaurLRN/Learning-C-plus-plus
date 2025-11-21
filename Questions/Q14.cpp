#include <iostream>
#include <algorithm>
#include <cctype>

void pprint_hashmap(unsigned int Count[26]);
void counter(unsigned int (&Count)[26], std::string userinp);

main()
{
unsigned int Count[26] = {};
// std::fill(Count, Count + 26, 0);
std::string userinp;
std::cout << "Enter The String To Detect: ";
std::cin >> userinp;

if(userinp.empty()){std::cout << "Please Enter Input!";}
else
{
    for(char c : userinp)
    {
        if(!std::isalpha(static_cast<unsigned char>(c))){std::cout << "Please Enter Valid Input!"; break;}
    }
}

counter(Count,userinp);
pprint_hashmap(Count);

return 0;
}

void pprint_hashmap(unsigned int Count[26])
{
    char c = 'A';
    for(int iter = 0; iter < 26; ++iter)
    {
    std::cout << static_cast<char>(static_cast<int>(c) + iter) << '=' << Count[iter] << '\n';
    }
    std::cout << std::endl;
}

void counter(unsigned int (&Count)[26], std::string userinp)
{
    for(char c : userinp)
    {
        // To Figure Out The Character From Both Lower or Uppercase Form, Maps both to same character
        int char_ascii = static_cast<int>(c);
        int index = (char_ascii >= 97) ? (char_ascii - 97) : (char_ascii - 65);
        Count[index] += 1;
    }
}