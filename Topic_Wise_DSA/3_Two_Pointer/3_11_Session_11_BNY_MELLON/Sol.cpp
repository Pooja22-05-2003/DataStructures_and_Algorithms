class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int i=0;
        int j=0;
        int n=arr.size();
        while(i<n && j<n){
            if(i==j){
                if(arr[i]!=0){
                    i++;
                    j++;
                }
                else {
                    j++;
                }
            }
            else {
                if(arr[j]==0){
                    j++;
                }
                else {
                    if(arr[i]==0){
                        swap(arr[i],arr[j]);
                        i++;
                        j++;
                    }
                }
            }
        }
    }
};