#include<bits/stdc++.h>
using namespace std;

int solve(int n, vector<int>arr){
  
    vector<int>track(n,0);

    vector<int>small(n,INT_MAX);
    int minn=INT_MAX;

    for(int i=n-1;i>=0;i--)
    {
        minn=min(minn,arr[i]);
        small[i]=minn;
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int curr=arr[i];
        bool found=false;
        for(int j=i+1;j<n;j++)
        {
           
            if(arr[j]>curr && !found)
            {
                if((small[j+1]<arr[j]) && ((i+1)<n)){
                ans+=5;
                 found=true;
                }
                else 
                {ans+=10;
                found=true;}
            }
            
            
        }
        if(!found) ans+=15;

        cout<<"ans:"<<ans<<endl;
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

  
    vector<int>arr(n);


    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
   

    cout<<
    solve(n,arr)<<endl;

    

    cout<<endl;
	return 0;
}
	

/*
input1 :
6
2
bacacc



Output 1:
6



input2 :
15
3
xxxxxxxxxxxxxxx



Output2:
144

*/





// // #include <bits/stdc++.h>
// // using namespace std;

// int mergeOverlappingIntervals(vector<vector<int>> &arr) {
//     int n = arr.size(); // size of the array

//     //sort the given intervals:
//     sort(arr.begin(), arr.end());

//     vector<vector<int>> ans;

//     for (int i = 0; i < n; i++) {
//         // if the current interval does not
//         // lie in the last interval:
//         if (ans.empty() || arr[i][0] > ans.back()[1]) {
//             ans.push_back(arr[i]);
//         }
//         // if the current interval
//         // lies in the last interval:
//         else {
//             ans.back()[1] = max(ans.back()[1], arr[i][1]);
//         }
//     }
//    return 2*(ans.size());
// }

// int main()
// {
    
//     vector<vector<int>> arr = {{2,4}, {3,5}, {6,7}};
//     int  ans = mergeOverlappingIntervals(arr);

  
//     cout <<ans <<endl;
//     return 0;
// }
