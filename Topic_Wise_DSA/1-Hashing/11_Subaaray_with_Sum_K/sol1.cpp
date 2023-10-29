//  TC=O(N)
//  SC=O(N)


//  Its code is little different then (Q: Largest Subarray with sum 0) 
//  ### Must see the difference

   int findSubArraySum(int Arr[], int N, int k)
    {
        // code here
        int ans=0;
        unordered_map<int,int> PrefixSum;
        int sum=0;
        
        for(int i=0;i<N;i++){
            sum+=Arr[i];
            // cout<<sum<<" ";
            if(sum==k) ans++;
           
                
            //  Don't use find function here
            //  Don't put this in the else condition.
            ans+=PrefixSum[sum-k];
            PrefixSum[sum]++;
            
          
        }
        
        
        
        
        return ans;
    }