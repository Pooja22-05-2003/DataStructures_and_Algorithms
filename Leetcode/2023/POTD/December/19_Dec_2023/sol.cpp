class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int row[8]={0 ,-1,-1,-1,0,+1,+1,+1};
        int col[8]={-1,-1,0,+1,+1,+1,0,-1};

        int r=img.size();
        int c=img[0].size();
        vector<vector<int>> ans(r,vector<int>(c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int sum=img[i][j];;
                int cnt=1;
                for(int k=0;k<8;k++){
                    int new_row=i+row[k];
                    int new_col=j+col[k];
                    // cout<<"i:"<<i<<" j:"<<j<<" row[k]:"<<row[k]<<" col[k]:"<<col[k]<<" newr:"<<new_row<<" newc:"<<new_col<<endl;
                    if(new_row>=0 && new_row<r && new_col>=0 && new_col<c){
                        sum+=img[new_row][new_col];
                        cnt++;
                    }


                }
                // cout<<"sum:"<<sum<<"cnt:"<<cnt<<endl;
                ans[i][j]=floor(sum/cnt);
            }
        }

        return ans;

    }
};