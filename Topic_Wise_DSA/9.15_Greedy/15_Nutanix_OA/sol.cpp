/*
1. By Observation , u will see if we arrange alhabets in the msg , according to their security valu sorted manner,
then it will give the min possible sum of the asjacet elements diff.
2. So make one arr and store the security value of all the alphabets.
3. Sort that arr
4. Find the sum of adjacent el diff.
5. Return that sum,
*/

// TC:O(slogs) // s is the size of the string
// SC:O(s)
#include<bits/stdc++.h>
using namespace std;

int  solve(string s ,vector<int>security_value){
    vector<int>arr;
    for(auto it :s)
    {
        arr.push_back({security_value[it-'a']});
    }

    sort(arr.begin(),arr.end());

    int ans=0;
    for(int i=1;i<arr.size();i++)
    {
        ans+=(arr[i]-arr[i-1]);
    }
    return ans;
}  


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********
    string s;
    cin>>s;

    vector<int>security_value={2,2,1,1,2,1,1,1,1,1,2,2,2,2,2,2,2,1,2,1,2,1,1,2,1,1};
    int ans=solve(s,security_value);
    cout<<"ans:"<<ans<<endl;
	return 0;
}
	

/*
input1 :
s=ksghtafb
security_value={2,2,1,1,2,1,1,1,1,1,2,2,2,2,2,2,2,1,2,1,2,1,1,2,1,1};

Output 1:
ans:7




input2 :
s=cbad
security_value={2,8,5,1,10,5,9,9,3,5,6,6,2,8,2,2,6,3,8,7,2,5,3,4,3,3};


Output2:
ans:1


*/


