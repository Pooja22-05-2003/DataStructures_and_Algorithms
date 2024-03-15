#include <bits/stdc++.h>
using namespace std;

struct Book{
    int BookID;    // 4 bytes
    char Title[20]; // 20 bytes
    float price;    // 4 bytes
};
int main()
{
    Book b1; // this b1 variable =? Total consume 28 bytes
    Book b2={100,"C++_Struct",400.0}; // asigning the value at the time of the declaration only

    strcpy(b1.Title,"Hello");
    b1.BookID=100;
    b1.price=500.00;

    Book b3;
    // copying the value from b1 to b3.
    b3=b1;



    return 0;
}