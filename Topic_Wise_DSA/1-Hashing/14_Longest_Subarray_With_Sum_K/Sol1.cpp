    
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
            //  Remeber to put this if condition , here , because we want the first index
            /*
            - See assume aapko sum=15 mila 1st index and 4th index  pe
            - Toh humme toh longest sub array chaiye na
            - Toh hum (15,1) ko 15,4 se kyu hi update karenge
            - Thats why hum phele check kar rhe hai ki if...humara sum phele exist nahi 
              karta hai tabhi hum map mein daalenge
            */
            if(PrefixSum.find(sum)==PrefixSum.end())PrefixSum[sum]=i;

           
        }
        return maxLen;
    }
