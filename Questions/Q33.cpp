#include <iostream>

inline double mod(double D){return (D < 0) ? (D*(-1)) : (D);}

class complex
{
    protected:
    double R, I;

    public:
    complex(double R, double I) : R(R), I(I) {}

    complex operator+(const complex& other) const
    {return complex((this->R + other.R),(this->I + other.I));}

    complex operator-(const complex& other) const
    {return complex((this->R - other.R),(this->I - other.I));}

    complex operator*(const complex& other) const
    {
        double a = this->R; double b = this->I;
        double x = other.R; double y = other.I;
        return complex((a*x - b*y),(b*x - a*y));
    }

    complex operator/(const complex& other) const
    {
        if(other.R == 0 && other.I == 0){exit(1);}
        double a = this->R; double b = this->I;
        double x = other.R; double y = other.I;
        double r = x*x + y*y; a/=r; b/=r;
        return complex((a*x + b*y),(b*x - a*y));
    }

    complex operator~() const
    {
        return complex((this->R),((-1)*(this->I)));
    }

    void print(std::string specific)
    {
        std::string sign = (this->I < 0) ? ("-") : ("+");
        std::cout << specific << " = " << (this->R) << sign << mod(this->I) << "i" << std::endl;
    }
};

int main()
{
    complex r1(10,12), r2(12,13);
    (r1+r2).print("Addition");
    (r1-r2).print("Subtraction");
    (r1*r2).print("Multiplication");
    (r1/r2).print("Division");
    (~r1).print("Conjugate");
    (~r2).print("Conjugate");
}