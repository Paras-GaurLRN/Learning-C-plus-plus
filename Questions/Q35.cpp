#include <fstream>
const int size = 13;

int main()
{
    std::ifstream file1("Q35_iofile1.txt");
    std::ofstream file2("Q35_iofile2.txt");

    char loaded_data[::size+1];
    std::string loaded_data_str;
    while(file1.eof() != 1)
    {
    file1.getline(loaded_data,::size+1);
    for(char ch : loaded_data)
    {
        if(ch != ' ' && ch != '\0' && ch != '\t' && ch != '\v' && ch != '\r' && ch != 10)
        {loaded_data_str += ch;}
    }
    file2 << loaded_data_str;
    }

    file1.close();
    file2.close();
    return 0;
}