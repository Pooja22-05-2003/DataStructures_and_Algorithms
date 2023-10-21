 int maxDistance(int arr[], int n)
    {
    //Code here
    
    //  Space -O(N)
    unordered_map<int,int>mp;
    int maxDist=0;
    
    //  Time Complexity =O(N)
    for(int i=0;i<n;i++){
        int el=arr[i];
        if(mp.find(el)!=mp.end()){
            maxDist=max(maxDist, i-mp[el]);
            continue;
        }
        else {
            mp[el]=i;
        }
    }
    
    return maxDist;
    }