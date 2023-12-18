
// TC=O(n2) 
// SC=O(1)

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &b,int n , int k , int g){
    int maxlen=0;
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(b[j]==g) cnt++;
            if(cnt<=k) maxlen=max(maxlen,(j-i+1));
        }
    }
    return maxlen;

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
    int g;
    cin>>g;
    int k;
    cin>>k;

    vector<int> arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    cout<<solve(arr,n,k,g)<<endl;
	return 0;
}
	


/*
// input1 :
9
5
2
5 5 6 7 8 8 6 5 5

// output1:
7


// input 2 :
8
7
1 2 3 4 5 6 7 8
// output 2:
4


*/
