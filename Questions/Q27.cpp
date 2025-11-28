#include <iostream>

// Doing the protected shenanigan makes constructor only visible to Derived classes
class Person{
    public:
    std::string name;
    void display();

    protected:
    Person(std::string name)
    {
        this->name = name;
    }
};

class Student : private Person {
    std::string course;
    short int marks;
    short int year;

    public:
    void display();
    Student(std::string name,std::string course,short int marks, short int year) : Person(name)
    {
        this->course = course;
        this->marks = marks;
        this->year = year;
    }
};

class Employee : private Person {
    std::string department;
    double salary;

    public:
    void display();
    Employee(std::string name,std::string department, double salary) : Person(name)
    {
        this->department = department;
        this->salary = salary;
    }
};

void Person::display()
{
    std::cout << "Person Object Display" << '\n';
    std::cout << "Name is " << (this->name) << std::endl;
}

void Student::display()
{
    std::cout << "Student Object Display" << '\n';
    std::cout << "Name is " << (this->name) << '\n';
    std::cout << "Course is " << (this->course) << '\n';
    std::cout << "Marks are " << (this->marks) << '\n';
    std::cout << "Year of Admission is " << (this->year) << std::endl;
}

void Employee::display()
{
    std::cout << "Employee Object Display" << '\n';
    std::cout << "Name is " << (this->name) << '\n';
    std::cout << "Department is " << (this->department) << '\n';
    std::cout << "Salary is " << (this->salary) << std::endl;
}

int main()
{
    Student std1("Stanford","English",45,2016);
    std1.display();

    Employee emp1("Stephan","HR",234567.23);
    emp1.display();
    
    return 0;
}