#include <iostream>

using namespace std;

class Complex {
public:
    double x,y;
    Complex(double a,double b) {
        x = a;
        y = b;
    }
    void Print() {
        cout << x << " + " << y << "i" << endl;
    }
    Complex operator + (Complex a) {
        return Complex(this->x + a.x, this->y + a.y);
    }
    Complex operator * (Complex a) {
         return Complex((this->x*a.x) - (this->y*a.y), this->x*a.y + this->y*a.x);
    }
    Complex operator - (Complex a) {
        return Complex(this->x - a.x, this->y - a.y);
    }
    Complex operator / (Complex a) {
        double t1, t2;
        t1 = (this->x * a.x + this->y * a.y) / (a.x * a.x + a.y * a.y);
        t2 = (this->y * a.x - this->x * a.y) / (a.x * a.x + a.y * a.y);
        return Complex(t1, t2);
    }
};

int main()
{
    Complex num1(1, 2);
    Complex num2(3, 4);
    Complex num3 = num1 + num2;
    Complex num4 = num1 - num2;
    Complex num5 = num1 * num2;
    Complex num6 = num1 / num2;
    num3.Print();
    num4.Print();
    num5.Print();
    num6.Print();
    return 0;
}