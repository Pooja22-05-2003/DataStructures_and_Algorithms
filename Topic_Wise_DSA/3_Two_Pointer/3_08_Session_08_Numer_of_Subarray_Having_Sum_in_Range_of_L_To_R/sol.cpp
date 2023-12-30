// Step 1 : Find number of subarrays with sum <= R

// Step 2 : Find number of subarrays with sum <= L-1

// return Step1 - Step2

// sum <= R includes subarrays with sum = {0, 1, 2 , 3 4 .... R} if exists
// sum <= L-1 includes subarrays with sum = {0,1,2,3,4,... L-1} if exists
// subtract both we get sum = {L, L+1, .. R} is exists

// return Ans

long long solve(vector<int> &arr, int n, long long k){
        long long sum = 0;
        long long ans = 0;
        int i = 0;
        int j = 0;
        
        while(j < n){
            sum += arr[j];
            while(sum > k){
                sum -= arr[i];
                i++;
            }
            
            ans += (j-i+1);
            j++;
        }
        return ans;
    }
    long long countSubarray(int N,vector<int> A,long long L,long long R) {
        return solve(A, N, R) - solve(A, N, L-1);
    }