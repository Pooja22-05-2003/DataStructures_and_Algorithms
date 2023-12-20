class Solution {
public:
    int solve(vector<int> b,int n , int k){
    int maxlen=0;
    int i=1;
    int j=1;
    int cnt=0;
    
    map<int,int>mp;
    // if(b[i]==g) cnt++;
    mp[b[1]]++;

    while(i<=n && j<=n){
        if(i==j){
            cnt=mp[b[i]];
            if(cnt>k){
                // if(b[i]==g) cnt--;
                i++;
                j++;
                // if(b[i]==g){
                    // if(b[i]<=n){
                    //     cnt++;
                    //     mp[b[j]]++;
                    //     }
                // }
                // if(i<=n) mp[b[i]]++;
            }
            else {
                //  as i to j is valid and both are at same index
                maxlen=max(maxlen,1);
                j++;
                if(j<=n){
                    // if(b[j]==g) cnt++;
                        mp[b[j]]++;
                 }
            }

        }

        else {
            cnt=mp[b[j]];
            if(cnt>k){
                //  it means i to j-1 is valid
                //  os automatically i+1 to j-1 will also be valid
                // if(b[i]==g) cnt--;
                mp[b[i]]--;
                i++;

                mp[b[j]]--;
                j--;

                if(i>j){
                    j=i;
                    // if(b[i]==g) cnt++;
                        mp[b[i]]++;
                }


            }
            else {
                int l=abs(j-i)+1;
                // cout<<"i:"<<i<<"j:"<<j<<endl;
                maxlen=max(maxlen,l);

                j++;
                if(j<=n){
                    // if(b[j]==g){
                    //     // cnt++;
                    // }
                        mp[b[j]]++;
                }
            }
        }
        
    }
    return maxlen;
    }
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>arr(n+1);
        for(int i=1;i<=n;i++){
            arr[i]=nums[i-1];
        }

        return solve(arr,n,k);
    }
};