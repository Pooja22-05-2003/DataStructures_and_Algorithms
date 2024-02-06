/*
1.check for the subarray which can't comtribute to the final sum. 
2. At each bit , try to remove the count of those subarrays.

*/
#include<bits/stdc++.h>
using namespace std;
   
    int  solve(vector<int> arr , int n) {

        // check for the bitwise 
        int ans=0;
        int TotalCountOfSubarray_at_ith_bit=((n*(n+1))/2);
        for(int i=0;i<32;i++)
        {
            
            vector<int>temp;
            for(int j=1;j<=n;j++)
            {
                int el=arr[j];
                int g=(el>>i);
                int val=(g&1);

                
                if(val==0)
                {
                    temp.push_back(j);
                }
            }


            int SubtractSubarray=0;
            if(temp.size()==0) continue;
            else if(temp.size()==1) TotalCountOfSubarray_at_ith_bit--;
            else 
            {
                int cnt=1;
                for(int k=1;k<temp.size();k++)
                {
                    
                    if((temp[k]-1 )== temp[k-1])
                    {
                       cnt++;
                    }
                    else 
                    {
                         SubtractSubarray+=(cnt)*(cnt+1)/2;
                         
                        cnt=1;
                    }
                }

                // last cnt also inlcude
                SubtractSubarray+=(cnt)*(cnt+1)/2;
            }

            SubtractSubarray=TotalCountOfSubarray_at_ith_bit-SubtractSubarray;
            int pow=(1<<i);
            ans+=(pow)*SubtractSubarray;
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

    int n;
    cin>>n;

    vector<int>arr(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    cout<<solve(arr,n);

	return 0;
}
	


/*
// input1 :
5 
1 2 3 4 5



// output1:
71


// input 2 :



// output 2:

*/