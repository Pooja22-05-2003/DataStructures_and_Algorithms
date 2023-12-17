// gfg soln :https://www.geeksforgeeks.org/number-subarrays-sum-less-k/
// TC=O(n) 
// SC=O(1)

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &b,int n , int k ){
    int i = 1 ;
    int j = 1 ;
    int cnt=0;
    // int ans=0;
    int sum=b[1];
    while(i<=n && j<=n){
        if(sum<k){
            j++;
            if(j>=i) cnt+=(j-i);
            // cout<<"cnt:"<<cnt<<" i:"<<i<<" j:"<<j<<endl;
            if(j<=n) sum+=b[j];
        }
        else {
            sum-=b[i];
            i++;
        }
    }

    return cnt;
}



int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********


    //*********
	int n;
    cin>>n;

    int k;
    cin>>k;

    vector<int> arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    cout<<solve(arr,n,k)<<endl;
	return 0;
}
	


/*
// input1 :
3
10
2 5 6

explaination :
Input : arr[] = {2, 5, 6}
        K = 10
Output : 4
The subarrays are {2}, {5}, {6} and
{2, 5},



// output1:
4


// input 2 :
5
10
1 11 2 3 15


{1}, {2}, {3} and {2, 3}

// output 2:
4


*/
