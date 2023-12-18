/*
optimal solution ...As this is a MONOTONOUS Function
Means if (i-j) goes invalid ...then (i to j+1) will also be invalid,(i to j+2)...will also be invalid and so on.
-> So, We can use 2 pointer here. if(we calcaulted count of i to j-1) then next time we will not start i to j (again calculation)
but we use the precompuatation value.
*/
// TC=O(n) 
// SC=O(1)

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &b,int n , int k , int g){
    int maxlen=0;
    int i=1;
    int j=1;
    int cnt=0;
    if(b[i]==g) cnt++;

    while(i<=n && j<=n){
        if(i==j){
            if(cnt>k){
                if(b[i]==g) cnt--;
                i++;
                j++;
                if(b[i]==g){
                    if(b[i]<=n)cnt++;
                }
            }
            else {
                //  as i to j is valid and both are at same index
                maxlen=max(maxlen,1);
                j++;
                if(j<=n){
                    if(b[j]==g) cnt++;
                 }
            }

        }

        else {
            if(cnt>k){
                //  it means i to j-1 is valid
                //  os automatically i+1 to j-1 will also be valid
                if(b[i]==g) cnt--;
                i++;

                if(b[j]==g) cnt--;
                j--;

                if(i>j){
                    j=i;
                    if(b[i]==g) cnt++;
                }


            }
            else {
                int l=abs(j-i)+1;
                maxlen=max(maxlen,l);

                j++;
                if(j<=n){
                    if(b[j]==g){
                        cnt++;
                    }
                }
            }
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
5


*/
