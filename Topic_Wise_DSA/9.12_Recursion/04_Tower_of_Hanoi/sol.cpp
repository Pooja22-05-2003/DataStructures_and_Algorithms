// TC=O(2^n)
// SC=O(n)

#include<bits/stdc++.h>
using namespace std;

//  Lets say n rods we have (n=3) A,B and C.
// Goal - Move n rod from rod A(source Rod) to rod C(Destination) through rod B(Helper Rod)
// 1. Call Recursion Move n-1 rod from rod A to B throught rod C.
// 2. Move the last rod from rod A to rod C.
// 3. Call Recursion and move n-1 rod from B to c through A


void TowerOFHanoi(int n, char A, char B, char C){
    if(n==0) return ;
    TowerOFHanoi(n-1,A,C,B);
    cout<<"Move Disc "<<n<< " from rod "<<A<< " to rod "<<C<<endl;
    TowerOFHanoi(n-1,B,A,C);
}


void solve(int n , char source, char helper, char Destination){
  
     TowerOFHanoi(n,'A','B','C');

}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********
//

    //*********

	int n;
    cin>>n;

    int pow;
    cin>>pow;
    
    solve(n,'A','B','C');
	return 0;
}
	


/*
// input1 :
3

// output1:

Move Disc 1 from rod A to rod C
Move Disc 2 from rod A to rod B
Move Disc 1 from rod C to rod B
Move Disc 3 from rod A to rod C
Move Disc 1 from rod B to rod A
Move Disc 2 from rod B to rod C
Move Disc 1 from rod A to rod C


// input 2 :


// output 2:



input3:


output3:

*/

