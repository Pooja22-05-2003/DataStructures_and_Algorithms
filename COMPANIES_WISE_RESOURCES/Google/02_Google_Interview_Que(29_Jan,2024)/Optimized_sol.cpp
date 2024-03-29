/*
TC :- O(Q*NlogN)

Takes O(N) extra space for Hashmap 


If (x,y)<=1000 -> then its feasible to store them in a matrix of size [1000][1000] and then the TC :- O(N)


*/

->read(n);
sorted_map<pair<int,int>,int> g 


count = 0 ;for(i=0;i<n;i++){
    
    if(operation==add(x,y)){
        g[{x,y}] = g[{x,y}] + 1 
    }
    if(operation==check(x,y)){
        
        for(auto u : g){//O(N)
            
            (x1,y1) = (u)
            if(y1==y && x1!=x){
                d = abs(x1-x)
                //found the second point
                x2 = x1
                y2 = y1 - d 
                
                
                x3 = x
                y3 = y2
                
                if(g[{x1,y1}]>=1 && g[{x2,y2}]>=1 && g[{x3,y3}]>=1){
                    count = count + g[{x1,y1}]*g[{x2,y2}]*g[{x3,y3}] 
                }
                
            }
            
            
            
        }
        
        
    }
    
    
    
}

print(count)



