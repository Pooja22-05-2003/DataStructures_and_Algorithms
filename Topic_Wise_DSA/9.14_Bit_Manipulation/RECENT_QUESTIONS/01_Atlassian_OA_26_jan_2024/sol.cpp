/*
Approach:
Observation:- 
1.Let’s say your number is 3 ; now you do its AND operation with any number in the world : - 3&x = the value will always be <=3 

x&y <= min(x,y) 


2.Now think how can you keep a[1],a[2],a[3],.......a[n] as it is; because it is sure that they can easily decrease so the best you can do is keep them as it is so their sum comes max possible.


3.To keep all numbers as they are and get the max sum :- x = “111111….” of this format




4.Is there any other x which could give the maximum sum and be less than this “11111111………”  

5.If in any row :- all numbers are 0 in that case; you can replace that bit of your x with 0 because it will make your x smaller and at the same time; keeping all the numbers the same hence its a better x. 


*/
/*

*/

#include<bits/stdc++.h>
using namespace std;

int  solve(vector<int>arr, int n ){

    vector<int>count(32,0);
    for(int i=0;i<=31;i++)
    {
        int cnt=0;
        for(int j=1;j<=n;j++)
        {
            int el=arr[j];
            int ith_bit=(el>>i);
            if((ith_bit&1)==0)
            {
               
            }
            else{
                cnt++;
            }
        }
      
        count[i]=cnt;
    }
    int num_ans=0;

    for(int i=0;i<=31;i++)
    {
        if(count[i]==0) 
        {}
        else num_ans+=(2<<i);
    }
    return num_ans;
}  


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********
//

    //*********

    int n ;
    cin>>n;

   
    vector<int>arr(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];

    }
    
    int ans=solve(arr,n);
    cout<<ans<<endl;

	return 0;
}
	

/*
input1 :
4
7 1 3 5


Output 1:
14




input2 :


Output2:



*/





