#include <iostream>

class Person{
    protected:
    std::string name;
    short unsigned int age;
    double salary;
    Person(std::string name, short unsigned int age, double salary) : name(name), age(age), salary(salary)
    {std::cout << "Person Constructor Called!" << '\n';}

    public:
    ~Person(){std::cout << "Person Destructor Called!" << '\n';}
};

class Engineer : virtual protected Person{
    public:
    Engineer(std::string name,short unsigned int age,double salary) : Person(name,age,salary)
    {std::cout << "Engineer Constructor Called!" << '\n';}
    ~Engineer(){std::cout << "Engineer Destructor Called!" << '\n';}
};

class Doctor : virtual protected Person{
    public:
    Doctor(std::string name,short unsigned int age,double salary) : Person(name,age,salary)
    {std::cout << "Doctor Constructor Called!" << '\n';}
    ~Doctor(){std::cout << "Doctor Destructor Called!" << '\n';}
};

// Diamond Inheritance Problem is resolved via Virtual keyword

class Laborer : virtual protected Person{
    public:
    Laborer(std::string name,short unsigned int age,double salary) : Person(name,age,salary)
    {std::cout << "Laborer Constructor Called!" << '\n';}
    ~Laborer(){std::cout << "Laborer Destructor Called!" << '\n';}
};

class Student : protected Engineer, protected Doctor, protected Laborer{
    protected:
    short unsigned int marks;

    public:
    Student(std::string name,short unsigned int age,double salary, short unsigned int marks) : 
    Person(name, age, salary), Engineer(name, age, salary), Doctor(name, age, salary), Laborer(name, age, salary)
    {
        std::cout << "Student Constructor Called!" << '\n';
        this->marks = marks;
    }
    ~Student(){std::cout << "Student Destructor Called!" << '\n';}
};

int main()
{
    std::cout << "Understanding How Multiple Inheritance Works" << '\n';
    std::cout << "Inheritance Map" << '\n' << '\n';
    std::cout << "Student ( Engineer , Doctor , Laborer )" << '\n';
    std::cout << "Engineer ( Person )" << '\n';
    std::cout << "Doctor ( Person )" << '\n';
    std::cout << "Laborer ( Person )" << '\n' << '\n';

    Student std1("Peter",18,60000.00,89);

    return 0;
}