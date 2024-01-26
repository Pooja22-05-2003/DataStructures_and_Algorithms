/*
Problem explaination
1. Bob has numbers in the array.
2. If maximum  number has occurence =1 (Then cnt++), then bob remove that from the array and insert number/2 in the array(If number/2 occurence=0, then don't insert it in the collection)
3. If the occurence has frequecny greater than 1 then remove all the occurence of that number.
4. Bob will count until the collection becomes empty.
5. Return the number of unique numbers present in Bob's collection.


Constraint 
1>=N<=10^5
0>=A[i]<=10^5
*/

/*
Approach:
1. As every time we need to pick the maximum element , so we need to use some data structure, which will store maximum element at the top.
2. So here We will use Priority Queue and also we need to store here the frequency (So we can use here hashing for that).

*/


// space:- O(N)[hashmap] + O(N)[priority Queue.]

// Tc :- O(N)[hashmap] + O(NlogN)[pq.] + O(N*log(N)) [Pushing ans Poopiing of element in the Priority Queue]


#include <bits/stdc++.h>

using namespace std;
int solve(int n , vector<int>arr)
{
    int cnt=0;
    unordered_map<int,int>freq;
    // First store the frequency of all the elements
    for(int i=1;i<=n;i++)
    {
        freq[arr[i]]++;
    }

    priority_queue<int>pq;

    // I will store all the element in the pq and will pick one by one from priority queue and parallely check its frequency in the hashmap
    for(auto it : freq)
    {
        pq.push(it.first);
    }

    while(!pq.empty())
    {
        int frontEl=pq.top();
         pq.pop();
        
        // check what is the frequency of that element in the hashmap
        int count=freq[frontEl];
        if(count==1)
        {   
            cnt++; // increment the count as that will consider in the final ans
            // it means it is unique
            int newEl=frontEl/2;
            
            // One condition is given that is num/2==0 then don't inset that in the collection.
            if(newEl==0)
            {
                // then do nothing
            }
            else 
            {
             freq[newEl]++;
             pq.push(newEl);   
            }

            // pop operation in the priority queue also happen from the as well.
         
            freq[frontEl]=0;
        }

        else if(count>1)
        {
            freq[frontEl]=0;
           
        }
        else 
        {
            // do nothing
        }


    }

    return cnt;

}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********
    //

    //*********
   
    int n;
    cin>>n;
    vector<int>arr(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    int ans=solve(n,arr);
    cout<<ans<<endl;
    
    return 0 ; 
}
/*
// // input1 :
5
1 2 3 3 4


// // output1:
2

// // input1 :

// // output1:

// */