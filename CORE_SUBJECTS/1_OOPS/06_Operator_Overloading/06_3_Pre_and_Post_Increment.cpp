#include <bits/stdc++.h>
using namespace std;

class Integer{

    int a;

    public:
    Integer(int x)
    {
        a=x;
    }

    void showdata()
    {
        cout<<a<<endl;
    }

    // unary pre and post increment operator

    Integer operator ++() // pre increment
    {
        int temp;
        temp=++a;
        return temp;
    }

    Integer operator ++(int) // post increment
    {
        int temp;
        temp=a++;
        return temp;
    }

};
int main()
{
    Integer x=2;
    Integer y=++x; // y=x.operator++()
    
    x=2;
    Integer z=x++; // z=x.operator++(int) [ int is passed in the paramter to differentiate it from pre increment]

    x=2;
    cout<<"x:";
    x.showdata();
    cout<<endl;

    cout<<"y:";
    y.showdata();
    cout<<endl;

    cout<<"z:";
    z.showdata();
    cout<<endl;

    return 0;
}