//  you go at each index ; you try to find the smallest subarray which is valid ending at index i 
//  using upper bound function hence you get j ; this means u can remove stuff from [j+1 to i] carefree ;
//   similarly u can do for [j to i] ; —> [j-1] to i] …….[2….i]....[1….i]  

// TC : O(N*logN) as at index i ; you use upper bound function which takes log(N) time per index ;
//  also storing all elements in the sets takes log(N) time per element ; so total time is
//   NlogN + NlogN = 2Nlogn = O(NlogN) okjii 


// soln link : https://ideone.com/iQ6izS



#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr,int n ){
    vector<int> increasing(n+1,0);
    vector<int> decreasing(n+1,0);

    increasing[n]=1;
    for(int i=n-1;i>=1;i-- ){
        if(arr[i]<=arr[i+1] && increasing[i+1]==1) increasing[i]=1;
    }

    // suffix[n]=1;
    // for(int i=n-1;i>=0 ;i--){
    //     if(arr[i]<=arr[i+1] && suffix[i+1]==1) suffix[i]=1;
    // }


    //  subarray 
    int ans=0;

    set<pair<int,int>> s;
    for(int i=1;i<=n;i++){
        int cnt=0;
        auto it=s.upper_bound({arr[i+1],INT_MAX}) ;// here we need the index(so u can give rough index as INT_MAX, just for formality it has no use)
        if(it!=s.begin()){
            // if(s.size()>=2){
            --it;
            pair<int,int> YY=*(it);
            int ind=YY.second;
            // cout<<"i:"<<ind<<" j:"<<i<<endl;
            cnt=cnt+ind;
            // }
        }

            if(increasing[i+1]==1 && (i+1<=n)){
                // means we can remove the (subarray from index 1 to i also)
                cnt++;
            }

            // if(increasing[i+1]==1){
            ans+=cnt;
            // }


            // now create decreasing array and also creat set of that
            if(i>=2 && arr[i-1]<=arr[i] && decreasing[i-1]==1){
                //  here decreasing array is different from the suffix array(which we used in O(n2))
                // decreasing [i]==1  is telling that from i to 1 all elements are in decreasing order
                decreasing[i]=1;
                s.insert({arr[i],i}); 
            }

            else if (i==1){
                decreasing[i]=1;
                s.insert({arr[i],i});
            }
            else {

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


    //*********
	int n;
    cin>>n;

    vector<int> arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    cout<<solve(arr,n)<<endl;
	return 0;
}
	


/*
// input1 :
4
1 2 1 2


// output1:
7


// input 2 :


// output 2:

*/
