/*
Approach :
1. Sort the array.
2. Then check for whether it is possible to achieve maximum greatness=1,2....and so on till n .
3. Whenever answer is no ....return the previous index.
4. check function will check using the comaprsion on the number of greatness to last n elements.

*/

// TC=O(nlogn)
// SC=O(1)

#include<bits/stdc++.h>
using namespace std;
bool check(int greatness, int n , vector<int> arr ){

    // Basically u need not to swap here.
    // U can check and return true or false;
    int i=greatness;
    int j=n;
    while(i>=0){

        if(arr[i]>=arr[j]) return false;
        i--;
        j--;
    }

    return true;


}
int  solve(vector<int> arr , int n ){
    // Asnwer will lie in some range

    // sort the array
    sort(arr.begin(),arr.end());
    int st=1;
    int end=n;
    bool found=false;
    int ans=0;

    while(st<=end && !found){
        int mid=(st+end)/2;
        // Pattern TTTTTTFFFFFF
        if(check(mid,n,arr)==true && check(mid+1,n,arr)==false){
            
            ans=mid;
            found=true;

        }

        else if (check(mid,n,arr)==false ){

            //  here st will move to mid and not mid-1
           end=mid-1;
        }
        else {
            st=mid+1;
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


    // int k;
    // cin>>k;
    vector<int> arr1(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr1[i];
    }

    cout<<solve(arr1 , n )<<endl;
	return 0;
}
	


/*
// input1 :
6
1 2 6 3 2 1

// output1:
4


// input 2 :
7
1 3 5 2 1 5 1

// output 2:
4

input3:
7
1 3 5 2 1 3 1

output3:
4

*/

/*
Approach :
1. Sort the array.
2. Then check for whether it is possible to achieve maximum greatness=1,2....and so on till n .
3. Whenever answer is no ....return the previous index.
4. check function will check using the comaprsion on the number of greatness to last n elements.

*/

// TC=O(nlogn)
// SC=O(1)

#include<bits/stdc++.h>
using namespace std;
bool check(int greatness, int n , vector<int> arr ){

    // Basically u need not to swap here.
    // U can check and return true or false;
    int i=greatness;
    int j=n;
    while(i>=0){

        if(arr[i]>=arr[j]) return false;
        i--;
        j--;
    }

    return true;


}
int  solve(vector<int> arr , int n ){
    // Asnwer will lie in some range

    // sort the array
    sort(arr.begin(),arr.end());
    int st=1;
    int end=n;
    bool found=false;
    int ans=0;

    while(st<=end && !found){
        int mid=(st+end)/2;
        // Pattern TTTTTTFFFFFF
        if(check(mid,n,arr)==true && check(mid+1,n,arr)==false){
            
            ans=mid;
            found=true;

        }

        else if (check(mid,n,arr)==false ){

            //  here st will move to mid and not mid-1
           end=mid-1;
        }
        else {
            st=mid+1;
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


    // int k;
    // cin>>k;
    vector<int> arr1(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr1[i];
    }

    cout<<solve(arr1 , n )<<endl;
	return 0;
}
	


/*
// input1 :
6
1 2 6 3 2 1

// output1:
4


// input 2 :
7
1 3 5 2 1 5 1

// output 2:
4

input3:
7
1 3 5 2 1 3 1

output3:
4

*/

