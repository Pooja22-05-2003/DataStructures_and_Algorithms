#include <bits/stdc++.h>
using namespace std;

/*
1. Static Local Variable
2. Static member variable
3. Static Member Functions.


1. Static Local variable.
{
    1.1 They are bydfault initialized to zero.
    1.2 Their lifetime is thoughout the program.
    1.3 When function is called then normal variable get memory, but the static variable can get memory at the start of the program,
    normal variables memory get destroyed when the scope of the function ends, but the static variable memory will not end until the program scope is end.

}

2.
{
    2.1 Static Member variable not belong to any class, but belong to any object.
    2.2 There will be only 1 copy of the static member variable for the whole class.
    2.3 Any object can use the same copy of variable.
    2.4 They can also be used with class name.
    
}

3. Static Member Functions
{
    3.1 They are qualified with the keyword static.
    3.2 They are also called class member functions
    3.3 They can be invoked with or without object
    3.4 They can only access static mebers of the class.
}


*/

void fun()
{
    // 1. Static Local variable.
    static int x; 
    int y;
}



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
};

float Account:: roi=1.22; // this is compulsory, for the static member variable to get memory, if we will not set any value, then its bydefault value set and that will be 0.

int main()
{

    
    Account::print(); // if roi is intilized then it is giving that answer, and if not initlized it was giving 0 as the answer.
    return 0;
}