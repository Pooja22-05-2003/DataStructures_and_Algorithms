/*
optimal solution ...As this is a MONOTONOUS Function
-> Now in google questions , instead of one g there are there are g's ., so replace the one g condition with three g's
in the same code
*/
// TC=O(n) 
// SC=O(1)

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &b,int n , int k1 , int g1 , int k2, int g2,int k3,int g3){
    int maxlen=0;
    int i=1;
    int j=1;
    int cnt1=0;
    int cnt2=0;
    int cnt3=0;
    if(b[i]==g1) cnt1++;
    if(b[i]==g2) cnt2++;
    if(b[i]==g3) cnt3++;

    while(i<=n && j<=n){
        if(i==j){
            if(cnt1>k1 || cnt2>k2 || cnt3>k3){
                    if(b[i]==g1) cnt1--;
                    if(b[i]==g2) cnt2--;
                    if(b[i]==g3) cnt3--;
                i++;
                j++;
                if(b[i]==g1){
                    if(b[i]<=n)cnt1++;
                }
                if(b[i]==g2){
                    if(b[i]<=n)cnt2++;
                }
                if(b[i]==g3){
                    if(b[i]<=n)cnt3++;
                }
            }
            else {
                //  as i to j is valid and both are at same index
                maxlen=max(maxlen,1);
                j++;
                 if(b[i]==g1){
                    if(b[i]<=n)cnt1++;
                }
                if(b[i]==g2){
                    if(b[i]<=n)cnt2++;
                }
                if(b[i]==g3){
                    if(b[i]<=n)cnt3++;
                }
            }

        }

        else {
            if(cnt1>k1 || cnt2>k2 || cnt3>k3){
                //  it means i to j-1 is valid
                //  os automatically i+1 to j-1 will also be valid
                 if(b[i]==g1){
                    if(b[i]<=n)cnt1--;
                }
                if(b[i]==g2){
                    if(b[i]<=n)cnt2--;
                }
                if(b[i]==g3){
                    if(b[i]<=n)cnt3--;
                }
                i++;

                  if(b[j]==g1){
                    if(b[j]<=n)cnt1--;
                }
                if(b[j]==g2){
                    if(b[j]<=n)cnt2--;
                }
                if(b[j]==g3){
                    if(b[j]<=n)cnt3--;
                }
                j--;

                if(i>j){
                    j=i;
                    if(b[i]==g1){
                    if(b[i]<=n)cnt1++;
                }
                if(b[i]==g2){
                    if(b[i]<=n)cnt2++;
                }
                if(b[i]==g3){
                    if(b[i]<=n)cnt3++;
                }
                }


            }
            else {
                int l=abs(j-i)+1;
                maxlen=max(maxlen,l);

                j++;
                if(j<=n){
                      if(b[i]==g1){
                    if(b[i]<=n)cnt1++;
                }
                if(b[i]==g2){
                    if(b[i]<=n)cnt2++;
                }
                if(b[i]==g3){
                    if(b[i]<=n)cnt3++;
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
    int g1;
    cin>>g1;
    int k1;
    cin>>k1;

    int g2;
    cin>>g2;
    int k2;
    cin>>k2;

    int g3;
    cin>>g3;
    int k3;
    cin>>k3;

    vector<int> arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    cout<<solve(arr,n,k1,g1,k2,g2,k3,g3)<<endl;
	return 0;
}
	


/*
// input1 :


// output1:



// input 2 :

// output 2:



*/
