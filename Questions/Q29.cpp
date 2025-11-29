#include <fstream>
#include <iostream>

unsigned int count = 0;

class Student{
    unsigned int roll_no;
    std::string name;
    unsigned int class_;
    unsigned short year;
    unsigned int total_marks;

    public:
    friend void setData(Student&);
    friend void setfile(std::ofstream& of,Student& S)
    {of << S.roll_no << '|' << S.name << '|' << S.class_ << '|' << S.year << '|' << S.total_marks << '\n';}
};

void setData(Student& S)
{
    unsigned int _roll_no, _class_, _total_marks;
    unsigned short _year;
    std::string _name;
    std::cout << "Enter Data for Student " << ++(::count) << '\n';
    std::cout << "Name : "; std::cin >> _name;
    std::cout << "Roll Number : "; std::cin >> _roll_no;
    std::cout << "Class : "; std::cin >> _class_;
    std::cout << "Year : "; std::cin >> _year;
    std::cout << "Total Marks : "; std::cin >> _total_marks;
    S.roll_no = _roll_no;
    S.name = _name;
    S.class_ = _class_;
    S.year = _year;
    S.total_marks = _total_marks;
}

void read_present(std::ifstream& If)
{
    char line[100];
    while(If.eof() != 1){
    If.getline(line,100);
    std::cout << line << std::endl;}
}

int main()
{
    Student StdAry[5];
    setData(StdAry[0]); setData(StdAry[1]); setData(StdAry[2]); setData(StdAry[3]); setData(StdAry[4]);

    std::ofstream ofile("Q29_iofile.txt");
    setfile(ofile,StdAry[0]); setfile(ofile,StdAry[1]); setfile(ofile,StdAry[2]); setfile(ofile,StdAry[3]); setfile(ofile,StdAry[4]);
    ofile.close();

    std::ifstream ifile("Q29_iofile.txt");
    std::cout << "Student Data:\n" << "Roll Number | Name | Class | Year | Total\n";
    read_present(ifile);
    ifile.close();

    return 0;
}