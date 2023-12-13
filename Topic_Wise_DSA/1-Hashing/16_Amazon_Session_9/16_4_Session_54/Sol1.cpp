/*
What we need to do⁉️🤔 - In Question we need to find two indexes i and j (1<=i<=j<=n) such that 
x[i] ^ x[i+1]^......x[j]=y[i]^y[i+1]^.......y[n]

Property used here of xor is (✨ xor of 2 numbers are 0 if they are same)

a[0] a[1]......a[n]
b[0] b[1]......b[n]

c[0]=(a[0]^b[0]) ,c[1](a[1]^b[1]) , c[2](a[2]^b[2].........c[n](a[n]^b[n]))

Now for finding the maximum length subarray.

Make one unordered_map<int,ind> ....now iterate in the c array...and if c[i] is present previously in the unordered_map
, then find the length of the subarray by (ind-mp[c[i]]+1) and maintain one max value update max value if the current lenght is
greater than the previous lenght 

*/





// TC=O(n)
// SC=O(n)

#include<bits/stdc++.h>
using namespace std;

int solve(int n , vector<int> X , vector<int> Y){
    vector<int> c(n+1);
    for(int i=1;i<=n;i++){
        c[i]=(X[i]^Y[i]);
    }

    vector<int> d(n+1);
    d[1]=c[1];
    for(int i=2;i<=n;i++){
        d[i]=c[i]^d[i-1];
    }

    unordered_map<int,int> mp;
    mp[0]=0;
    int maxlen=0;
    
    for(int i=1;i<=n;i++){
        if(mp.find(d[i])!=mp.end()){

            // if i and j have same number in d array ....means i to j-1 xor is 0
            int len=(i-mp[d[i]]);
            maxlen=max(maxlen,len);

        }

        mp[d[i]]=i;
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
    vector<int> X(n+1);
    vector<int> Y(n+1);

    for(int i=1;i<=n;i++){
        cin>>X[i];
    }

    for(int i=1;i<=n;i++){
        cin>>Y[i];
    }

    cout<<solve(n,X,Y)<<endl;
	return 0;
}
	


/*
// input1 :
5
10 4 10 10 8
2 2 1 9 6

// c=8 6 11 3 14
// d=8 14 5 6 8  

If you choose i = 2 and j = 5

    X2 ⊕ X3 ⊕ X4 ⊕ X5 = 4 ⊕ 10 ⊕ 10 ⊕ 8 = 12

    Y2 ⊕ Y3 ⊕ Y4 ⊕ Y5 = 2 ⊕ 1 ⊕ 8 ⊕ 6 = 12

    G = j-i+1 = 5-2+1 = 4



// output1:
// 4

// input 2 :


// output 2:

*/
