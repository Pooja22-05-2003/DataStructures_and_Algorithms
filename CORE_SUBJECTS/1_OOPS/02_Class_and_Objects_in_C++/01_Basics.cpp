/*
1. In C++ Structure, by default all the members of structures are public.
2. In C++ Classes, by default all the members are private.

*/

/*
Features of class and object:

1. Object consumes memory but class does not consume any memory.
2. Class is description of an object.
3. Object is an instance of the class.


4. Instance member variable are also called=> Attributes, Data Members , Fields , Properties
5. Instance member functions are also called=> Methods, Procedure , Actions , Operations and sevices.
*/

#include <bits/stdc++.h>
using namespace std;
class Complex{
    private:
    int a,b; // a and b are instance member(Object ke variable) variable and not class variables.

    public:
    void set_data(int ,int);  // if we are defining this outside the class, but atleast we need to declare it inside the class

    void show_data()   // These functions are called instance member functions
    {
        cout<<a<<" "<<b<<endl;
    }


    // ------2) Add function
    Complex add(Complex c)
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
    Complex c1;
    c1.set_data(2,3); //c1 is an object => Object consumes memory but class does not consume any memory.
    c1.show_data();



    //----------2) Add Two Complex Numbers
    Complex a;
    a.set_data(1,2);

    Complex b;
    b.set_data(3,4);

    Complex x;
    x=a.add(b);

    x.show_data();  // ans=(4,6)

    return 0;
}