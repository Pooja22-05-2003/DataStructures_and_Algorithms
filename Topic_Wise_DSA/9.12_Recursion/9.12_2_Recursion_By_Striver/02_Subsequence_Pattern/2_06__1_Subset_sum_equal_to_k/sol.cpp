// TC=O(2^n*n)
// SC=O(n)
#include <bits/stdc++.h>
using namespace std;

    void solve(int ind,vector<int>&temp ,vector<vector<int>>& ans,vector<int>& nums,int k, int sum){
       
        if(ind>=nums.size()){
            if(sum==k){
          
            ans.push_back(temp);
            }
            // ✨You forgot to add this return statement 
            return;
        }

        // take the current index
        temp.push_back(nums[ind]);
        sum+=nums[ind];
        solve(ind+1,temp,ans,nums,k,sum);
        // not take the current index
   
        sum-=nums[ind];
        temp.pop_back();
        solve(ind+1,temp,ans,nums,k,sum);

    }
    vector<vector<int>> subsets(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
    
        solve(0,temp,ans,nums,k,0);
        return ans;
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

    vector<vector<int>> ans=subsets(nums,k);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }

        cout<<endl;
    }



    return 0;
}


/*
//  input1 :
3
1 2 1


// output1:
1 1
2


input 2:


Output 2:





*/