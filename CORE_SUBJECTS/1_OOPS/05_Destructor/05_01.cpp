/*
1.  Destructor is an instance member function of a class.
2. The name of the destructor is same as the name of a clss but preceded by the title (~) symbol.
3. Destructor can never be static.
4. Destructor has no return type.
5. Destrcutor takes no argument (No Overloading is Possible).

6. ** Destructor is invoked implicitly when objects is going to destory.(Destructor object ke life mei chalne wala last function hota hai, iska matlab ye nahi hn ki destructor object ko destroy kr rha hai.)

7. WHY DESTRUCTOR?
=> It should be defined to release resources allocated to an object.



*/

#include <bits/stdc++.h>
using namespace std;



class Account 
{
    private:
    int balance;      // Instance Member Variable

    // roi= rate of interest 
    static float roi; // Static Member Variable or also called (Class Variable)
    // by writing this much only, it will not get memory, we need also initialize it outside the class

    public:
    void setBalance(int b)
    {
        balance=b;
    }

    static void print() // this is now static Member function, it means is can be access without creating any object
    {
        cout<<roi<<endl;
    }

    ~Account()
    {
        // Use Defined Destructor.
        cout<<"Destructor Called!"<<endl;
    }
};

float Account:: roi=1.22; // this is compulsory, for the static member variable to get memory, if we will not set any value, then its bydefault value set and that will be 0.

int main()
{

    
    Account a1;
    return 0;
}