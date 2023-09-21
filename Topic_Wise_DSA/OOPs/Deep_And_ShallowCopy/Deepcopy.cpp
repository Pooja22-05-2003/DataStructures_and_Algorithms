#include <bits/stdc++.h>
using namespace std;

class Student{
    public:
    char * name;
    int rollNo;
    int age;

    Student(int rollNo, int age , char*name){
        this->rollNo=rollNo;
        this->age=age;
        this->name=new char[strlen(name)+1];
        strcpy(this->name,name);
    }

    void print(){
        cout<<"Roll No : "<< rollNo<< " Age :"<<age << " Name :"<< name<<endl;
    }


};

int main(){
    char name[]="Pooja";

    Student s1(1,20,name);
    s1.print();

    name[2]='j';
    Student s2(2,21,name);
    s2.print();

    s1.print();


}