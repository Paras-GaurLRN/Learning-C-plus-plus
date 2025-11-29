#include <fstream>
#include <iostream>

int main()
{
    std::string data;
    std::cout << "Enter Content : ";
    std::getline(std::cin,data);

    std::ofstream file1o("Q30_iofile1.txt");
    file1o << data;
    file1o.close();

    std::ifstream file1i("Q30_iofile1.txt");
    std::ofstream file2("Q30_iofile2.txt");

    std::size_t size = data.length();
    char loaded_data[size+1];
    file1i.getline(loaded_data,size+1);

    std::string loaded_data_str;
    for(char ch : loaded_data)
    {
        if(ch != ' ' && ch != '\0') {loaded_data_str += ch;}
    }

    file2 << loaded_data_str;
    file1i.close();
    file2.close();
    std::cout << "Data Processed and Saved in Q30_iofile2.txt\n";
    return 0;
}