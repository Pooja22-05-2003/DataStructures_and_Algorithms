

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