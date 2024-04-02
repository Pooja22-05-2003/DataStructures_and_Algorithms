// TC : O(n)
// SC : O(n)

// Link:->https://ideone.com/F3yFZg
n
->read(n)


->b[n]
->read(b[n])
hashmap <int,int> g 

for(i=0;i<n;i++){//O(N)
    read(b[i])
    g[b[i]] = g[b[i]] + 1 
    //Java.-> g.put(b[i],g.getOrDefault(b[i],0)+1)
}
ans = 0 check = 1 
for(auto u : g){//O(N)
    x = u->second;
    if(x==1){
        check = 0 
    }
    if(x%3==0){
        v = x/3;
    }
    else
    {
        v = x/3 + 1
    }
    ans = ans + v 
}
if(check==0){
    ans = -1
}
print(ans)





