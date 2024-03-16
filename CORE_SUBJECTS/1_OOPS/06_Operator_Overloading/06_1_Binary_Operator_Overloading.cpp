/*
Operator Overloading:

1. When an operator is overloaded with multiple jobs, it is known as operator Overloading.
2. It is a way to implement Complile Time Polymorphism.


* Rules to Remember:
1. Any symbol can be used as function name if these conditions are satisfied.
 1.1 -> If it is a valid operator in C++ laguage .
 1.2 -> If it is preceded by operator keyword.

2. We  cannot overload (sizeof) and ?: operator.

*/


#include <bits/stdc++.h>
using namespace std;
class Complex{
    private:
    int a,b; 

    public:
    void set_data(int ,int);  

    void show_data()  
    {
        cout<<a<<" "<<b<<endl;
    }


    // ------2) Operator Overloading
    Complex operator +(Complex c)
    {
        Complex temp;
        temp.a=a+c.a;
        temp.b=b+c.b;

        return temp;
    }
};

    // this is called membership label(Complex::  (Scope resolution operator-::))
void Complex:: set_data(int x,int y)
{
    a=x;
    b=y;
}
int main()
{
  
    Complex a;
    a.set_data(1,2);

    Complex b;
    b.set_data(3,4);

    Complex x;
    // x=a+b; // 1st way
    x=a.operator+(b); // 2nd way to write this

    x.show_data();  // ans=(4,6)

    return 0;
}
