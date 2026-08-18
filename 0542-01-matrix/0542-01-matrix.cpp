class Solution {
public:
bool valid(int i,int j ,int m,int n){
    if(i>m-1||j>n-1||j<0||i<0)return false;
    return true;
}
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
          int level=0;
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                }
                else mat[i][j]=-1;
            }
        }
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto [r,c]=q.front();
                q.pop();
               if(valid(r-1,c,m,n)&&mat[r-1][c]==-1){
                q.push({r-1,c});
                mat[r-1][c]=level+1;
               }
                if(valid(r,c+1,m,n)&&mat[r][c+1]==-1){
                q.push({r,c+1});
                mat[r][c+1]=level+1;
               }
                if(valid(r,c-1,m,n)&&mat[r][c-1]==-1){
                q.push({r,c-1});
                mat[r][c-1]=level+1;
               }
                if(valid(r+1,c,m,n)&&mat[r+1][c]==-1){
                q.push({r+1,c});
                mat[r+1][c]=level+1;
               }
            }
            level++;
        }
        return mat;
    }
};