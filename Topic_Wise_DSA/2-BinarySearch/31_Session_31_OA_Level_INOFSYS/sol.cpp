/*

Approach:
1. Sort the array.
2. Now for any number its minimum difference would always be it from its adjacent el.
3. Store the maximum possible minimum difference.
4. Now using binary search try to find (whether it was possile to p pairs such that maximum possible diff=1 is possible or not. (Means all the 2 pairs must have diff<=1)....If answer is NO....
then try for maximum possible diff=2 is possible or not????.....If ans is NO......increase the number till maxDiff)
Wherever u got the answer as YES first time (That would be your answer, so return that answer).
5. We can do this using linear search also (But it would cost hight time complexity).
6. Try to reduce the time complexity using Binary Search.

*/


// TC=O(maxDiff*nlogn) [For loop is running for maxDiff time and (sorting of arr takes logn time)]
// SC=O(1)

#include<bits/stdc++.h>
using namespace std;
bool check(int ii,int p,int n , vector<int> arr){
    sort(arr.begin(),arr.end());
    int cnt=0;
    // p pairs must have diff <=i;
    int i=2;
    while(i<=n){
        if((arr[i]-arr[i-1])<=ii) {
            cnt++;
            i=i+2;
            if(cnt>=p) break;
        }
        else {
            i=i+1;
        }
    }

    if(cnt>=p) return true;
    else return false;
 
}

int solve(vector<int> arr , int n , int p){
    
    sort(arr.begin(),arr.end());
    int maxDiff=INT_MIN;
    int ans=-1;
    // linear search
    for(int i=2;i<=n;i++){
        maxDiff=max(maxDiff,(arr[i]-arr[i-1]));
    }
    for(int i=0;i<=maxDiff;i++){
        if(check(i,p,n,arr)==true){
            ans=i;
            break;
        }
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

    int p;
    cin>>p;

    vector<int> arr(n);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    cout<<solve(arr,n,p)<<endl;
	return 0;
}
	


/*
// input1 :
6
2
10 1 2 7 1 3

// output1:
1

// input 2 :
4
1
4 2 1 2

// output 2:
0

input3:


output3:


*/

