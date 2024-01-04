bool solve(int ind, int sum, int k, vector<int>&a){
    // base case4
    if(sum>k) return false;
    if(ind>=a.size()){
        if(sum==k) return true;
        else return false;
    }


    // take
    sum+=a[ind];
    bool left=solve(ind+1,sum,k,a);
    if(left==true) return true;
    sum-=a[ind];
    bool right=solve(ind+1,sum,k,a);
    if(right) return true;
    return false;
    
}


bool isSubsetPresent(int n, int k, vector<int> &a)
{
    // Write your code here

    return solve(0,0,k,a);
    
}