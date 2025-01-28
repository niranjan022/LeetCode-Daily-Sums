class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int maxf = 0;
        int m = grid.size(),n=grid[0].size();
        // vector<int> add(n+1,0);
        // grid.push_back(add);
        // grid.insert(grid.begin(),add);
        // for(auto& arr:grid){
        //     arr.push_back(0);
        //     arr.insert(arr.begin(),0);
        // }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0){
                    int s = 0;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    while(!q.empty()){
                        auto [x,y] = q.front();
                        q.pop();
                        if(grid[x][y]>0){
                            s+=grid[x][y];
                            grid[x][y]=0;
                            if(x>0 and grid[x-1][y]>0) q.push({x-1,y});
                            if(x<m-1 and grid[x+1][y]>0) q.push({x+1,y});
                            if(y>0 and grid[x][y-1]>0) q.push({x,y-1});
                            if(y<n-1 and grid[x][y+1]>0) q.push({x,y+1});
                        }
                    }
                    maxf=max(maxf,s);
                }
            }
        }
        return maxf;
    }
};