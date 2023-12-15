// pseudo code 
// TC=O(N3)
// SC=O(1)

/*
-> arr
-> n+1

for(int i=1;i<=n;i++){
    for(int j=i;j<=n;j++){
        if(arr[i-1].....arr[0] is sorted and and arr[j+1]......arr[n] is sorted) cnt++; // O(N) time
    }
}


*/