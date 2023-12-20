https://leetcode.com/problems/trapping-rain-water/description/

// Time Complexity = O(n)
// Space Complexity =O(n)

class Solution {
public:
    int trap(vector<int>& height) {
    // use hashing (prefix and suffix array)
    int n=height.size();
    vector<int> prefix(n);
    vector<int> suffix(n);
    int lmax=INT_MIN;
    int rmax=INT_MIN;
    for(int i=0;i<n;i++){
        prefix[i]=max(lmax,height[i]);
        lmax=max(height[i],lmax);
    }
    for(int i=n-1;i>=0;i--){
        suffix[i]=max(rmax,height[i]);
        rmax=max(height[i],rmax);
    }

    for(int i=0;i<n;i++){
        cout<<"prefix[i]:"<<prefix[i]<<" suffix[i]:"<<suffix[i]<<endl;
    }
    //  now compute the final ans with formula 
    //  ans+=min(lmax,rmax)-arr[i]
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=(min(prefix[i],suffix[i])-height[i]);
    }

    return ans;
    }
};

// input:
// [0,1,0,2,1,0,1,3,2,1,2,1]
// output:
// 6
/*
prefix[i]:0 suffix[i]:3
prefix[i]:1 suffix[i]:3
prefix[i]:1 suffix[i]:3
prefix[i]:2 suffix[i]:3
prefix[i]:2 suffix[i]:3
prefix[i]:2 suffix[i]:3
prefix[i]:2 suffix[i]:3
prefix[i]:3 suffix[i]:3
prefix[i]:3 suffix[i]:2
prefix[i]:3 suffix[i]:2
prefix[i]:3 suffix[i]:2
prefix[i]:3 suffix[i]:1

*/