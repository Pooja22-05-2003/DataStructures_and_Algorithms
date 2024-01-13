/*
Approach :
1. As in the questions , it was asking to find the number of ways, So here we can use DP.
2. dp[i] will store the best answer till index 'i', when the last element 'i' must be included int he answer.
3. So let's say , we calculating 

s="1234"
dp[4]= number of ways such that '4' is put in the last box.(We can include this in our ans , only when 4<=k)
     + number of ways such that '3 4' is put in th last box (We can include this in our ans , only when 34<=k)
     + number of ways such that ' 2 3 4' is put in th last box (We can include this in our ans , only when 234<=k)
     + number of ways such that '1 2 3 4' is put in th last box(We can include this in our ans , only when 1234<=k)

dp[i]=dp[i-1]+dp[i-2]+.......dp[0]

// NOTE : INTIALIZE dp[0]=1 , IF ( The whole string is valid , then it will add dp[i-1] means dp[0] in the answer and that is 1).

Special condition is :-> dp[i-1] will only be considered if “i”<=K ; 
->dp[i-2] will only be considered if “i-1,i”<=K
->dp[i-3] will only be considered if “i-2,i-1,i”<=K

-> dp[i] = number of ways to divide [1……i] such that it is guaranteed that all the divisions will be <=K 

*/



// TC= O(n2)
// SC= O(n)



// TC= O(n2)
// SC= O(n)
#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;
int  solve(string s,int k) 
{
    int n=s.size();
    // Convert this string to integer and put in some vector.
    vector<int>arr(n+1);

    int i=0;
    while(i<n){
        arr[i+1]=(s[i]-'0');
        i++;
    }

    vector<int> dp(n+1,0);
    dp[0]=1;

    i=1;
    while(i<=n){
        int j=i-1;
        
        while(j>=0 ){

            // we are considering 1 based indexing , but actual is 0 based in string.
            // in 1 based , we need to consider from j+1 to i
            int l=abs(j-i);
//  There are two parameters in this function of substring: pos and len
            string ss=s.substr(j+1-1,l);
            int nn=stoi(ss);
            // cout<<"i:"<<i<<" j:"<<j<<" num:"<<nn<<endl;
            if(nn<=k && arr[j+1]!=0){
                dp[i]=(dp[i]+dp[j])%mod;
            }
            
            else {
                // means add nothinh
                dp[i]=dp[i]+0;
                
            }
            j--;
        }
        // cout<<"i:"<<i<<" dp[i]:"<<dp[i]<<endl;
        i++;
    }

    return dp[n];
  
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********
//

    //*********

   string s1;
   cin>>s1;
    int k;
    cin>>k;
    cout<<solve(s1,k);

	return 0;
}
	


/*
// input1 :
123
1000


// output1:
4


Input2:
125
24

// output 2:
2

input3:
1234
1000

output:
7

input4:
1234
100

output: 
5


*/