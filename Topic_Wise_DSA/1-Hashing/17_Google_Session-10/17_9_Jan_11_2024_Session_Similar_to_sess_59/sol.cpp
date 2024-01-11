/*
Appraoch:
Similar to Google Session 59
1. Here we can pic only those 5 elements which are satisying all the 5 conditions.
Condition:b[i] < b[j] > b[k] < b[l] > b[m] 
2. Make one prefix array  and for each index count the number of pairs each element is satisying .(b[i] < b[j] )
3. Similarly create one suffix array and for each index count the number of pairs each element is satisying ( b[l] > b[m] )
4. Now run one for loop using k  and check for each index on the left hand size if (j=k-1 and j>=1) check how many elements satsying th econdition and find left for each element satisying the condition. (left=prefix[j])
  Similary check (l=k+1 and l<=n) and check for each pair satisfying the condition b[k]<b[l] and for each pair, check suffix [k] and that is the right .
  => For each index k , calculte int temp=left*right . and do add that in the answer.
5. After all the k iteration return the final answer.
*/

// TC= O(N2)
// SC=O(M)
#include<bits/stdc++.h>
using namespace std;
   
    int  solve(vector<int> b , int n ) {

        vector<int> prefix_i_j(n+1,0);
        for(int j=1;j<=n;j++){
            int cnt=0;
            for(int i=j-1;i>=1;i--){
                if(b[i] < b[j]) cnt++;
            }
            prefix_i_j[j]=cnt;
        }


        vector<int> suffic_l_m(n+1,0);
        for(int l=n;l>=1;l--){
            // b[l] > b[m] 
            int cnt=0;
            for(int m=l+1;m<=n;m++){
                if(b[l] > b[m] ) cnt++;
            }
            suffic_l_m[l]=cnt;
        }
        int ans=0;
        for(int k=1;k<=n;k++){
            int left=0;
            int right=0;
            // b[i] < b[j] > b[k] < b[l] > b[m] 
            for(int j=k-1;j>=1;j--){
                if(b[j] > b[k]) left+=prefix_i_j[j];
            }

            for(int l=k+1;l<=n;l++){
                if(b[k] < b[l]) right+=suffic_l_m[l];
            }

            ans+=(left*right);

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
6
1 
2
1
2
1
0


// output1:
2


// input 2 :



// output 2:

*/