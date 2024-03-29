/*
O(N^2) Time and O(1) size.
*/

->read(n)
->b[n]

ans = 0 
for(i=0;i<n;i++){
    int g = 0 ; 
    for(j=i;j<n;j++){
        g = (g | b[j]) //OR[i.....j]
        ans = ans + g 
    }
}
print(ans)



