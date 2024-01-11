/*
Approach :
dp[i] = minimum number of partitions if array is of size “i” ; all the partitions are of size>=K 
and all the partitions have max - min <=M 


Dp[i] = 1 + dp[i-1] →(1>=K) (big-small<=m)

OR 

1 + dp[i-2] -> (2>=K) (b-s<=m)

OR

1 + dp[i-3] -> (3<=K)

OR
….

1 + dp[0] -> (i<=K)


*/


// TC=O(N2)

// SC=O(N)


// 1st if the array given to u is 0 based then convert it into 1 based indexing.

--> b[n+1] // arr of 1 based indexing
-> dp[n+1] ={INT_MAX} // Intialize with large value.
-> dp[0]=0;

int i=0;
for(int i=0;i<n;i++){
    big=b[i]
    small=b[i]

    for(j=i;j>=0 ;j--){

        if(big-small<=m && (i-j)>=k){
            if(dp[j]!=INT_MAX) dp[i+1]=min(dp[i+1],1+dp[j]);
        }

        big=max(mib,b[j])
        small=min(small,b[j])
    }
}

--> return dp[n]


/*
Super Efficient solution

Super efficient solution.--> was not needed in Cisco OA.

Final Observation.-> max - min can only increase. 
So there is always a limit (l,r) from which u need to find the min(1+dp[l….r])

-> If you want to calculate dp[i] ; all you need is min of the range (l,r) of dp(l,r) —> 1 + dp[l…..r]

-> you can find the minimum number in a range from (l,r) using a segment tree in O(logN)



*/