    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
               unordered_map<int,int> PrefixSum;
        int maxLen=0;
        int sum=0;
        for(int i=0;i<N;i++){
            /*
             0   1  2   3  4  5
            10  15  17  24 25 34
            -5  0   2  15  16 19
            10->0
            0->1
            2->1
            */
            sum+=A[i];
            if(sum==K) maxLen=max(maxLen,i+1);
           
           else {
            if(PrefixSum.find(sum-K)!=PrefixSum.end()) 
            {
                maxLen=max(maxLen,(i-PrefixSum[sum-K]));
                
            }
           
           }
            
            if(PrefixSum.find(sum)==PrefixSum.end())PrefixSum[sum]=i;

           
        }
        return maxLen;
    }
