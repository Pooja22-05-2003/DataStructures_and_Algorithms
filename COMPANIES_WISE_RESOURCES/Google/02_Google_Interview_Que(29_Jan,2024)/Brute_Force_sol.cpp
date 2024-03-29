/*
TC - O(Q*N^3) ; Q = number of query N = size of array B
Takes extra O(N.) size. 

*/


->read(n);b-> array of pairs.



count = 0 ;for(i=0;i<n;i++){
    
    if(operation==add(x,y)){
        b.push(x,y)
    }
    if(operation==check(x,y)){
        
        for(i1=0;i1<b.size(),i1++){
            for(j1=i1+1;j1<b.size(),j1++){
                for(d1=j1+1;d1<b.size(),d1++){
                    if(check_square(x,y,b[i1][0],b[i1][1],b[j1][0],b[j1][1],b[d1][0],b[d1][1])){
                        count = count + 1 
                    }
                }
            }
        }
        
        
    }
    
    
    
}

print(count)
