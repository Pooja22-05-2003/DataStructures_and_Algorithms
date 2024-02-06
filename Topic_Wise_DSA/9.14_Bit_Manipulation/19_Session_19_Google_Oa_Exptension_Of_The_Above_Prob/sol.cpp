/*
1.check for the subarray which can't comtribute to the final sum. 
2. At each bit , try to remove the count of those subarrays.

*/
// Sir sol link :https://ideone.com/nUj3Lg
// TC=O(n*32*32)
// SC=O(32)
#include<bits/stdc++.h>
using namespace std;
    int nCr(int a,int b)
    {
        int ans=1;
        // formula a!/(b!*(a-b)!) 
        if(b>a) return 0;
        for(int i=0;i<b;i++)
        {
            ans=ans*(a-i);
            ans=ans/(i+1);
        }

        return ans;
    }
    int  solve(int l, int r, int n ,vector<int> arr ,vector<vector<int>> prefix_cnt_1, vector<vector<int>> prefix_cnt_0,int msb) {
        int sum=0;
       
        for(int k=0;k<=msb;k++)
        {
        int cnt_1=0;
        int cnt_0=0;
        if(l==0) {
            cnt_1=prefix_cnt_1[k][r];
            cnt_0=prefix_cnt_0[k][r];
        }
        else 
        {
        cnt_1=prefix_cnt_1[k][r]-prefix_cnt_1[k][l-1];
        cnt_0=prefix_cnt_0[k][r]-prefix_cnt_0[k][l-1];
        }
        
        int total=0;

        total+=nCr(cnt_1,3);
        total+=cnt_1*nCr(cnt_0,2);

        sum+=((1<<k)*total);


        }

        

    return sum;
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

    vector<int>arr(n+1);
    int max_el=0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        max_el=max(max_el,arr[i]);
    }

   int msb = 0;  // msb of the max. element. 
 
for(int i=31;i>=0; i--) 
{
    int mask = 1<<i;
 
    int val = max_el & mask; 
 
    if(val!=0) {msb=i; break;}
} 
    vector<vector<int>> prefix_cnt_1(31,vector<int>(n,0));
    vector<vector<int>> prefix_cnt_0(31,vector<int>(n,0));


    for(int i=0;i<=msb;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int el=arr[j];
            int val=(1&(el>>i));

            if(j==1)
            {
            if(val==0)
            {
                prefix_cnt_0[i][j-1]=1;
                prefix_cnt_1[i][j-1]=0;
                
            }

            else 
            {
                prefix_cnt_1[i][j-1]=1;
                 prefix_cnt_0[i][j-1]=0;
            }

            }
            else 
            {if(val==0)
            {
                prefix_cnt_0[i][j-1]=1+prefix_cnt_0[i][j-1-1];
                prefix_cnt_1[i][j-1]=prefix_cnt_1[i][j-1-1];
                
            }

            else 
            {
                prefix_cnt_1[i][j-1]=1+prefix_cnt_1[i][j-1-1];
                prefix_cnt_0[i][j-1]=prefix_cnt_0[i][j-1-1];
            }


            }

            // cout<<"i:"<<i<<" j:"<<j-1<<endl;
            // cout<<" prefix_cnt_0[i][j-1]:"<< prefix_cnt_0[i][j-1]<<"  prefix_cnt_1[i][j-1]:"<< prefix_cnt_0[i][j-1]<<endl;
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l;
        cin>>r;
        cout<<solve(l,r,n,arr,prefix_cnt_1,prefix_cnt_0,msb)<<endl;
    }

 

	return 0;
}
	


/*
// input1 :
5
1 2 3 4 5
3
0 2
1 3
1 4



// output1:
0
5
14




// input 2 :



// output 2:

*/