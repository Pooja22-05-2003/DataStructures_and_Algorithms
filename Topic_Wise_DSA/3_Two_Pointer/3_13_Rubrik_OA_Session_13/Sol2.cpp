/*
Approach
1. Run a single for loop if i to j is valid then , it len would be (j-i+1)
2. update max with max len and 
3. Update i to j+1.( because if i to j+1 is not valid, then i+1 to j+1 would also be not valud till i to j)
*/
// TC=O(n) 
// SC=O(1)

#include<bits/stdc++.h>
using namespace std;


int solve(vector<int> arr1, vector<int>arr2,int n){
    int maxLen=0;
    unordered_map<int,int> mp;
    for(int i=1;i<=n;i++){
        mp[arr2[i]]=i;
    }

    int cnt=0;
    int i=1;
    int j=1;
    while(i<=n){
        int cnt=1;
        j=i;
        while(j<=n-1){
            if(mp[arr1[j]]<mp[arr1[j+1]]) {
                cnt++;
                j++;
            }
            else {
                break;
            }
        }
         maxLen=max(maxLen,cnt);
         i=j+1;
    }
    return (n-maxLen);
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

    vector<int> arr1(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr1[i];
    }

    vector<int> arr2(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr2[i];
    }
    cout<<solve(arr1,arr2,n)<<endl;
	return 0;
}
	


/*
// input1 :
6
4 2 3 1 5 6 
3 1 4 6 5 2


// output1:
3 (from index 3 to 5= subarray 3 1 5)


// input 2 :

// output 2:



*/
