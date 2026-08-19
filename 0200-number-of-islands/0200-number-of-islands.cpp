class Solution {
public:
     bool valid(int i,int j ,int m,int n){
    if(i>m-1||j>n-1||j<0||i<0)return false;
    return true;
}
    void bfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>>& vis,int m,int n){
        queue<pair<int,int>>q;
        q.push({row,col});
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            vis[r][c]=true;
            if(valid(r-1,c,m,n)&&!vis[r-1][c]){
                if(grid[r-1][c]=='1'){
                    q.push({r-1,c});
                    vis[r-1][c]=true;
                }
              }
              if(valid(r+1,c,m,n)&&!vis[r+1][c]){
                if(grid[r+1][c]=='1'){
                    q.push({r+1,c});
                    vis[r+1][c]=true;
                }
              }
              if(valid(r,c-1,m,n)&&!vis[r][c-1]){
                if(grid[r][c-1]=='1'){
                    q.push({r,c-1});
                    vis[r][c-1]=true;
                }
              }
              if(valid(r,c+1,m,n)&&!vis[r][c+1]){
                if(grid[r][c+1]=='1'){
                    q.push({r,c+1});
                    vis[r][c+1]=true;
                }
              }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]&&grid[i][j]=='1'){
                    bfs(i,j,grid,vis,m,n);
                    ans++;
                }
            }
        }
        return ans;
    }
};