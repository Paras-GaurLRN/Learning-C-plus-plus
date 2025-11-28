#include <iostream>
#include <math.h>

class Triangle{
    double A,B,C;

    public:
    Triangle(double A,double B,double C)
    {
        if((A <= 0) || (B <= 0) || (C <= 0) || (A+B<=C) || (A+C<=B) || (B+C<=A))
        {std::cout << "Please Enter Valid Inputs";}
        this->A = A;
        this->B = B;
        this->C = C;
    }

    double Area()
    {
        double S = (A+B+C)/2 ;
        return std::sqrt(S*(S-A)*(S-B)*(S-C));
    }

    double Area(double H, double B)
    {
        if((H <= 0) || (B <= 0))
        {std::cout << "Please Enter Valid Inputs";}
        return ((H * B) / 2);
    }
};

int main()
{
    Triangle T1(4,5,6);
    std::cout << "Heron's Formula For Area = " << (T1.Area()) << '\n';
    std::cout << "Area from Right Angled Triangle Formula = " << (T1.Area(3,4)) << std::endl;
    return 0;
}