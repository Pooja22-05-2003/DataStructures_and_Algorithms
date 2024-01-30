#include <bits/stdc++.h>
using namespace std;

int solve(int n , int y, vector<int>arr)
{
    int ans=0;
    
    for(int i=60;i>=0;i--){
        int BitWise_OR=0;
        for(int j=1;j<=n;j++)
        {
            int num=arr[j];
            int g=(num>>i);
            int ith_bit=0;
            if(g&1==1)
            {
                ith_bit=1;
            }
            else ith_bit=0;
            
            BitWise_OR=BitWise_OR|ith_bit;
            
        }
        
        int gg=(y>>i);
        int target=0;
        if(gg & 1==1)
        {
            target=1;
        }
        else target=0;
        

        if(BitWise_OR==target) 
        {// then do nothing
        }
        else 
        {
            if(BitWise_OR==1 && target==0) 
            {
                // ans not possible
                return -1;
            }
            else 
            {
                // cout<<"ans:"<<ans<<" i:"<<i<<endl;
                ans=ans|(1<<i);
            }
        }
        
        
    }
    
    return ans;
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int y;
	    cin>>y;
	    vector<int>arr(n+1);
	    for(int i=1;i<=n;i++)
	    {
	        cin>>arr[i];
	    }
	    
	    cout<<solve(n,y,arr)<<endl;
	}
	

}


/*
Input :
4
4 15
3 5 6 2
3 8
1 2 1
1 1
0
5 7
1 2 4 2 1

Output :
8
-1
1
0

*/