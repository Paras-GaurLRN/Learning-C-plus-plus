#include <iostream>
#include <fstream>

const int size = 100;

class Student{
    std::string name;
    unsigned short age;
    char sex;
    float height;
    float weight;

    public:
    Student()
    {
        std::cout << "Enter Data:\n" << "Name : "; std::getline(std::cin,name);
        std::cout << "Age : "; std::cin >> age;
        std::cout << "Gender : "; std::cin >> sex;
        std::cout << "Height : "; std::cin >> height;
        std::cout << "Weight : "; std::cin >> weight;
        std::cout << std::endl;
    }
    friend void write(Student&,std::ofstream&);
};

void write(Student& S,std::ofstream& Of)
{
    Of << S.name << ' ' << S.age << ' ' << S.sex << ' ' << S.height << ' ' << S.weight << '\n';
}

void read(std::ifstream& If)
{
    while(If.eof() != 1)
    {
        char loaded_data[::size+1];
        If.getline(loaded_data,size+1);
        std::cout << loaded_data << '\n';
    }
    std::cout << std::endl;
}

int main()
{
    Student Std1;
    std::ofstream ofile("Q36_iofile.txt");
    write(Std1,ofile);
    ofile.close();

    std::ifstream ifile("Q36_iofile.txt");
    read(ifile);
    ifile.close();
}