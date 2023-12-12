/*
Approach:
--> n , k and array is given .
--> find the minimum effort , by choosing any element x from the array. effort= For all i=1 to k sum[(arr[i]-x)]

-> ✨ Now , if we want to find the minimum sum , we need to choose the correct x value.
-> ✨ Best x value , is the median value after sorting the array.
-> ✨ If the subarray(k pair elements which u are picking) is of even length , then find the effort from both the median value.
-> ✨ If the subarray (k pair elements which u are picking is of odd length) , then find the effort from the meadian value of the array.


-> ⁉️🤔 Which k number u should select--> Select the k number in sorted order, as they will give the min effort value .
-> Using 1 for loop ...use sliding window of k size and calculate effort and store the minimum effort in min valriable.

-> U can also calculate effort for 1 pair in O(1) operation.

*/


// TC=O(n)
// SC=O(n)


#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> arr , int n , int k) {
    /*
    1. Sort the array 
    2. Pick the continuos k ele from the array.
    3.u can calclaute the sum of the k size array using the prefix sum
    */

    sort(arr.begin(),arr.end());

    vector<int> prefix(n+1,0);
    for(int i=1;i<=n;i++){
        prefix[i]=prefix[i-1]+arr[i];
    }
   int i=1;
   int minAns=INT_MAX;

   while(i<=n-k+1){
           int st=i;
           int end=k+i-1;

           if(k%2!=0){

           
           int mid=(st+end)/2;

         // st--> mid-1
           int l1=abs(mid-st);
           int sum1=(prefix[mid-1]-prefix[st-1]);
           int ans1=abs(l1*arr[mid]-sum1);
        //    minAns=min(minAns,sum1);


            // mid+1--->d
           
           int l2=abs(end-mid);
           int sum2=(prefix[end]-prefix[mid]);
           int ans2=abs(l2*arr[mid]-sum2);        


           int finalsum=ans1+ans2;
           minAns=min(minAns,finalsum);

          
           }

           else {
            int mid1=(st+end)/2;
            int mid2=mid1+1;

         // st--> mid-1
           int l1=abs(mid1-st);
           int sum1=(prefix[mid1-1]-prefix[st-1]);
           int ans1=abs(l1*arr[mid1]-sum1);
        //    minAns=min(minAns,sum1);


            // mid+1--->d

           
           int l2=abs(end-mid1);
           int sum2=(prefix[end]-prefix[mid1]);
           int ans2=abs(l2*arr[mid1]-sum2);        


           int finalsum=ans1+ans2;
           minAns=min(minAns,finalsum); 


        //    -->2nd mid
           l1=abs(mid2-st);
           sum1=(prefix[mid2-1]-prefix[st-1]);
           ans1=abs(l1*arr[mid2]-sum1);
        //    minAns=min(minAns,sum1);


            // mid+1--->d

           
           l2=abs(end-mid2);
           sum2=(prefix[end]-prefix[mid2]);
           ans2=abs(l2*arr[mid2]-sum2);        


           finalsum=ans1+ans2;
           minAns=min(minAns,finalsum); 
           }




        i++;
   }

    return minAns;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********


    //*********
    // 1-- based indexing are used here

    int n ;
    cin>>n;
    int k;
    cin>>k;

    vector<int> arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    cout<<solve(arr,n,k);
   
}






/*

input :
7
3
3 9 5 1 8 6 4



output:
2


*/

