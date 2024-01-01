//  Brute force
//  Time Complexity=O(N2)
//  space complexity=O(1)
class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int maxSum=INT_MIN;
        int n=arr.size();

        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=arr[j];
                maxSum=max(maxSum,sum);
  
            }
        }

        return maxSum;
    }
};