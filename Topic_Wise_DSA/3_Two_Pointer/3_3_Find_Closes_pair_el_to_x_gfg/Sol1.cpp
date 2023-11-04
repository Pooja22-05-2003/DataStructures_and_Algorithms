class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        //code here
        int mindiff=INT_MAX;
        int i=0;
        int j=m-1;
        int FinalEl1=0;
        int FinalEl2=0;
        while(i<n && j>=0){
            
        if(abs(x-(arr[i]+brr[j]))<mindiff){
             mindiff=min(mindiff, abs(x-(arr[i]+brr[j])));
             FinalEl1=arr[i];
             FinalEl2=brr[j];
             
         }
        
         if (arr[i]+brr[j]>=x) {
             j--;
         }
         else {
             i++;
         }
            
        }
        
        vector<int> ans;
      
       
        ans.push_back(FinalEl1);
        ans.push_back(FinalEl2);
        return ans;
    }
};