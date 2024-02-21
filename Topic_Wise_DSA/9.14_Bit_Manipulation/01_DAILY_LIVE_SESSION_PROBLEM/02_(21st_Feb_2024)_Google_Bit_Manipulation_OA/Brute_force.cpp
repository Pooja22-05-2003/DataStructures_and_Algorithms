/*
Pseudocode:
-> n. 
-> b[n+1]
mv = 0 
for(int i=1;i<=n;i++){
    
    g = b[i]
    
    for(int j=i;j<=n;j++){
        //[i......j].
        g = (g&b[j])
        mv = max(mv,g);
    }
}

ml = 0 
for(int i=1;i<=n;i++){
    
    g = b[i]
    
    for(int j=i;j<=n;j++){
        //[i......j].
        g = (g&b[j])
        
        g---> AND[i.....j]
        if(g==mv){
            l = abs(i-j) + 1 
            ml = max(ml,l)
        }
    }
}

print(ml)


TC - O(2*N^2) = O(N^2)
SC :- O(1)

*/