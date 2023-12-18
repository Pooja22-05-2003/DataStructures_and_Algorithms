/*
Approach
1.Run from loop by taking 2 pointer ,i=1; and j=n...now for i=1..if(arr[i]+arr[j]<k), it means..that i can piar up with i+1...till j
2. So , add that number in your ans.
3. if condition not satisigying (if condition) , then do j--
4. when i crosse j , then return answer

*/
// TC=O(n) 
// SC=O(1)

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &b,int n , int k  ){
    int i = 1 ;
    int j = n ;

    int ans=0;
    while(i<j){
        int sum=b[i]+b[j];
        if(sum<k){
          
            sum+=b[j];
            //  measn l can pair with all ele from l+1 to r
            int valid_j_cnt=(j-i);
            ans+=valid_j_cnt;
            i++;

        }
        else {

            j--;
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

    int k;
    cin>>k;

    vector<int> arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    cout<<solve(arr,n,k)<<endl;
	return 0;
}
	


/*
// input1 :
6
7
1 3 7 9 10 11
// output1:
1 There is only one pair (1, 3)


// input 2 :
8
7
1 2 3 4 5 6 7 8
// output 2:
6
Pairs are (1, 2), (1, 3), (1, 4), (1, 5)
          (2, 3) and (2, 4)  


*/
