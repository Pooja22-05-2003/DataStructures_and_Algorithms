#include <bits/stdc++.h>
using namespace std;
class Complex{
    int real;
    int img;
    public:
    Complex(int  real=0 , int img=0){
        this->real=real;
        this->img=img;
    }

    Complex operator+(Complex c2){
        Complex ans;
        ans.real=this->real+c2.real;
        ans.img=this->img+c2.img;
        return ans;
    }
     void ShowData(){
        cout<<"Real :"<<real<<" Img:"<<img<<endl;
     }


};

int main(){

    Complex c1(1,2);
    c1.ShowData();
    Complex c2(3,4);
    Complex c3=c1+c2;
    c2.ShowData();
    c3.ShowData();

    return 0;
}