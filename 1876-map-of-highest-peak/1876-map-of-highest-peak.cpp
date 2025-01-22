class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int row = isWater.size();
        int col = isWater[0].size();
        vector<vector<int>> ans(row,vector<int>(col,row+col));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(isWater[i][j]==1){
                    ans[i][j]=0;
                }
                else{
                    if(i>0){
                        ans[i][j] = min(ans[i][j],ans[i-1][j]+1);
                    }
                    if(j>0){
                        ans[i][j] = min(ans[i][j],ans[i][j-1]+1);
                    }
                }
            }
        }
        for(int i=row-1;i>=0;i--){
            for(int j=col-1;j>=0;j--){
                if(i<row-1){
                    ans[i][j]=min(ans[i][j],ans[i+1][j]+1);
                }
                if(j<col-1){
                    ans[i][j]=min(ans[i][j],ans[i][j+1]+1);
                }
            }
        }
        return ans;
    }
};