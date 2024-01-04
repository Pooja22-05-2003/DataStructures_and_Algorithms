// TC=O(2^n*n) [For each indexes there are 2 options to pick or not pick. SO for each indexes, also we are pushing the temp in ans vector which will take O(n) time]
// SC=O(n) [ Maximum at one time recursion depth can go up to all the indexed which are equal to n]


#include <bits/stdc++.h>
using namespace std;

    void solve(int ind,vector<int>&temp ,vector<vector<int>>& ans,vector<int>& nums){
        if(ind>=nums.size()){
            ans.push_back(temp);
            // ✨You forgot to add this return statement 
            return;
        }

        // take the current index
        temp.push_back(nums[ind]);
        solve(ind+1,temp,ans,nums);
        // not take the current index

        temp.pop_back();
        solve(ind+1,temp,ans,nums);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0,temp,ans,nums);
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
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    vector<vector<int>> ans=subsets(nums);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }

        cout<<endl;
    }
    cout<<"{}"<<endl;


    return 0;
}


/*
//  input1 :
3
1 2 3


// output1:
1 2 3 
1 2 
1 3 
1 
2 3 
2 
3 

{}


input 2:


Output 2:





*/