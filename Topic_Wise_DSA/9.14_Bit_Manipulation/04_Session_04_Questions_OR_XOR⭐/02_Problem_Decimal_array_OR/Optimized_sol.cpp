// TC=O(N*32)
// SC=O(1)

/*
1. This question is similar to previous question, but here we have not any binary array.
2. So, at each bit, we will do  the same as we did in the previous ques.


*/
#include<bits/stdc++.h>
using namespace std;

int solve(int n ,vector<int>arr){
    int ans=0;
    for(int i=0;i<=31;i++)
    {

        int cnt_1=0;
        int sum=0;
        for(int j=1;j<=n;j++)
        {
            int num=arr[j];
            // check if that is set or not
           
            int g=(num>>i);
            if((g&1)==1)
            {
                int total_Valid_pairs=j-1;
                sum+=total_Valid_pairs* (pow(2,i));
                 cnt_1++;
            }
            else {
                int total_Valid_pairs=cnt_1;
                sum+=total_Valid_pairs* (pow(2,i));
               
            }
           
        }
        ans+=sum;
      

       
    }

    return ans;
    
}  

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********
     
    // Enter the decimal number.
    int n;
    cin>>n;

    vector<int>arr(n+1);

    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    cout<<solve(n,arr)<<endl;
	return 0;
}
	


/*
// input1 :
4
1 2 3 4

// output1:
27


// input 2 :
3
5 10 15

// output 2:







*/

