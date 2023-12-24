/*
Approach :
-> Applied binary search on the brute force solution

*/

// TC=O(logn)
// SC=O(1)
#include<bits/stdc++.h>
using namespace std;
bool check(int day,int No_Of_Chocolate ){
    // calculate the maximum number of chocolate u can eat with (day given)
    // if day is even
    int sum=0;
    if(day%2==0){
    int n1=day/2;
    int n2=day/2;

    int s1=(n1*(n1+1))/2;
    int s2=(n2*(n2+1)/2);

    sum=s1+s2;
    }
    else {
        int n1=day/2;
        int n2=(day/2)+1;
        int s1=(n1*((n1+1)/2));
        int s2=(n2*((n2+1)/2));

        sum=s1+s2;
    }

    if(sum>=No_Of_Chocolate) return true;
    else return false;


}
int  solve( int No_Of_Chocolate){
    // Asnwer will lie in some range

    int st=1;
    int end=No_Of_Chocolate;
    bool found=false;
    int ans=No_Of_Chocolate;

    while(st<=end && !found){
        int mid=(st+end)/2;

        if(check(mid,No_Of_Chocolate)==true && check(mid-1,No_Of_Chocolate)==false){
            
            ans=mid;
            found=true;

        }

        else if (check(mid,No_Of_Chocolate)==false ){

            //  here st will move to mid and not mid-1
           st=mid+1;
        }
        else {
            end=mid;
        }

    }
   
    return ans;
  
}




int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********
//

    //*********
	// int n;
    // cin>>n;


    int k;
    cin>>k;
    // vector<int> arr1(n+1);
    // for(int i=1;i<=n;i++){
    //     cin>>arr1[i];
    // }

    cout<<solve(k)<<endl;
	return 0;
}
	


/*
// input1 :
8

// output1:
5


// input 2 :
6

// output 2:
4

input3:


output3:


*/

