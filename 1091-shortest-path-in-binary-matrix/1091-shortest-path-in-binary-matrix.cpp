class Solution {
public:
    bool valid(int r,int c,int n){
        return r>=0&&c>=0&&c<n&&r<n;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ans=-1;
        int level=1;
        int n=grid.size();
        queue<pair<int,int>>q;
        if(grid[0][0]==0&&grid[n-1][n-1]==0)q.push({0,0});
        else return ans;
        vector<vector<int>>vis(grid.size(),vector<int>(grid.size(),0));
        vis[0][0]=1;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto [r,c]=q.front();
                q.pop();
                if(r==n-1&&c==n-1)return level;
                if(valid(r-1,c-1,n)&&grid[r-1][c-1]==0&&vis[r-1][c-1]==0){
                    q.push({r-1,c-1});
                    vis[r-1][c-1]=1;
                }
                 if(valid(r-1,c,n)&&grid[r-1][c]==0&&vis[r-1][c]==0){
                    q.push({r-1,c});
                    vis[r-1][c]=1;
                }
                 if(valid(r,c-1,n)&&grid[r][c-1]==0&&vis[r][c-1]==0){
                    q.push({r,c-1});
                    vis[r][c-1]=1;
                }
                 if(valid(r+1,c-1,n)&&grid[r+1][c-1]==0&&vis[r+1][c-1]==0){
                    q.push({r+1,c-1});
                    vis[r+1][c-1]=1;
                }
                 if(valid(r-1,c+1,n)&&grid[r-1][c+1]==0&&vis[r-1][c+1]==0){
                    q.push({r-1,c+1});
                    vis[r-1][c+1]=1;
                }
                 if(valid(r,c+1,n)&&grid[r][c+1]==0&&vis[r][c+1]==0){
                    q.push({r,c+1});
                    vis[r][c+1]=1;
                }
                 if(valid(r+1,c,n)&&grid[r+1][c]==0&&vis[r+1][c]==0){
                    q.push({r+1,c});
                    vis[r+1][c]=1;
                }
                 if(valid(r+1,c+1,n)&&grid[r+1][c+1]==0&&vis[r+1][c+1]==0){
                    q.push({r+1,c+1});
                    vis[r+1][c+1]=1;
                }
            }
            level++;
        }
        return ans;
    }
};