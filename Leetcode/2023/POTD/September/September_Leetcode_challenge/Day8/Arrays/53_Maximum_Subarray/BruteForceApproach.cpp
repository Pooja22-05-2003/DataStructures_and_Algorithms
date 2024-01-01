//  Brute force
//  Time Complexity=O(N3)
//  space complexity=O(1)
class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int maxSum=INT_MIN;
        int n=arr.size();

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int sum=0;
                for(int k=i;k<=j;k++){    
                    sum+=arr[k];
                }
                maxSum=max(maxSum,sum);
            }
        }

        return maxSum;
    }
};