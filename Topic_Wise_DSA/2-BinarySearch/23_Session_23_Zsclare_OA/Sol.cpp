/*
Approach :
Que ??? Minimize the maximum possible (It means we need to make all the element smaller than equal to el)
1. The lowest possible value is the first index element (because we can only add in that index)....and can't do any subtraction.
2. Maximum possbile value of the answer is maximum element of the array.(We need to minimize that as much as possible ,we can do.)
3. The optimal approach ...is start with the last value and gradually shift to the left.

*/
#include<bits/stdc++.h>
using namespace std;
bool check(int mid,vector<int>arr,int n){
    int i=n;
    while(i>=2){
        if(arr[i]>=mid){
            int x=abs(arr[i]-mid);
            arr[i-1]=arr[i-1]+x;
            arr[i]=arr[i]-x;
        }
        i--;
    }
    if(arr[1]<=mid) return true;
    else return false;
}
int  solve( vector<int> arr , int n){
    int st=0;
    int max_el=INT_MIN;
    for(int i=0;i<n;i++){
        max_el=max(max_el,arr[i]);
    }
    int end=max_el;
    bool found=false;
    int ans=INT_MIN;
    while(st<=end && found==false){
        int mid=(st+end)/2;
        cout<<"check(mid):"<<check(mid,arr,n)<<endl;
        if(check(mid,arr,n)==true && check(mid-1,arr,n)==false){
            ans=mid;
            found=true;

        }
        else if (check(mid,arr,n)==false && check(mid+1,arr,n)==false){
            st=mid+1;
        }
        else if(check(mid,arr,n)==true && check(mid-1,arr,n)==true){
            end=mid-1;
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

    vector<int> arr1(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr1[i];
    }

    cout<<solve(arr1,n)<<endl;
	return 0;
}
	


/*
// input1 :
5
5 2 1 7

// output1:
5


// input 2 :
5
5 2 1 7 5

// output 2:
5

input3:


output3:


*/

