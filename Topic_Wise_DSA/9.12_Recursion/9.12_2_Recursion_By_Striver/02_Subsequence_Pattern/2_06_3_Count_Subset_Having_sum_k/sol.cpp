// TC=O(2^n*n)
// SC=O(n)
#include <bits/stdc++.h>
using namespace std;

    int  solve(int ind,int sum,vector<int>& nums,int k){
       
        if(ind==nums.size()){
            if(sum==k){
                 return 1;
            }
            // ✨You forgot to add this return statement 
            else return 0;
        }

        // take the current index
        sum+=nums[ind];
        int left=solve(ind+1,sum,nums,k);
        sum-=nums[ind];
        int right=solve(ind+1,sum,nums,k);
        return left+right;

    }
    int  subsets(vector<int>& nums, int k) {

       return  solve(0,0,nums,k);
       
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
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    cout<<subsets(nums,k)<<endl;
   


    return 0;
}


/*
//  input1 :
3
1 2 1


// output1:

2


input 2:
4
2
1 2 1 1

Output 2:
4




*/