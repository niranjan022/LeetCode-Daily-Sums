class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long s = 0;
        int n = grid[0].size();
        for(int i=0;i<n;i++) s+=grid[0][i];
        long long s1=0;
        int row=0;
        for(int i=0;i<n;i++){
            if(row!=1){
                s-=grid[0][i];
                s1+=grid[1][i];
                if(s1>s){
                    grid[row][i]=0;
                    row++;
                }    
            }
            grid[row][i]=0;
        }
        s=0,s1=0;
        for(int i=0;i<n;i++){
            s+=grid[0][i];
            s1+=grid[1][i];
        }
    
        return max(s,s1);
    }
};