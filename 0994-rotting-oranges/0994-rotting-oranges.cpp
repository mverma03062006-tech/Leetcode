class Solution {
public:
int ans=0;
    bool check(vector<vector<int>>& grid){
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)return true;
            }
        }
        return false;
    }
    void bfs(vector<vector<int>>& grid,queue<pair<int,int>>& q,int & ans){
        
        int m=grid.size(),n=grid[0].size();
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto [r,c]=q.front();
                q.pop();
                if(c<n-1&&grid[r][c+1]==1){
                    q.push({r,c+1});
                    grid[r][c+1]=2;
                }
                if(r>0&&grid[r-1][c]==1){
                    q.push({r-1,c});
                    grid[r-1][c]=2;
                }
                if(c>0&&grid[r][c-1]==1){
                    q.push({r,c-1});
                    grid[r][c-1]=2;
                }if(r<m-1&&grid[r+1][c]==1){
                    q.push({r+1,c});
                    grid[r+1][c]=2;
                }
            }
            if(!q.empty())ans++;
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
      queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
       
        bfs(grid,q,ans);
        if(check(grid))return -1;
        return ans;
    }
};