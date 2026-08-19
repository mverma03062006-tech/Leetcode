class Solution {
public:
    bool valid(int i,int j ,int m,int n){
    if(i>m-1||j>n-1||j<0||i<0)return false;
    return true;
}
    int numEnclaves(vector<vector<int>>& grid) {
         int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            if(grid[i][0]==1){
                q.push({i,0});
                grid[i][0]=2;
            }
            if(grid[i][n-1]==1){
                q.push({i,n-1});
                grid[i][n-1]=2;
            }         
        }
        for(int i=1;i<n-1;i++){
            if(grid[0][i]==1){
                q.push({0,i});
                grid[0][i]=2;
            }
            if(grid[m-1][i]==1){
                q.push({m-1,i});
                grid[m-1][i]=2;
            }
        }
         while(!q.empty()){
              auto [r,c]= q.front();
              q.pop();
              if(valid(r-1,c,m,n)){
                if(grid[r-1][c]==1){
                    q.push({r-1,c});
                    grid[r-1][c]=2;
                }
              }
              if(valid(r+1,c,m,n)){
                if(grid[r+1][c]==1){
                    q.push({r+1,c});
                    grid[r+1][c]=2;
                }
              }
              if(valid(r,c-1,m,n)){
                if(grid[r][c-1]==1){
                    q.push({r,c-1});
                    grid[r][c-1]=2;
                }
              }
              if(valid(r,c+1,m,n)){
                if(grid[r][c+1]==1){
                    q.push({r,c+1});
                    grid[r][c+1]=2;
                }
              }
        }
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)count++;
            }
        }
        return count;
    }
};