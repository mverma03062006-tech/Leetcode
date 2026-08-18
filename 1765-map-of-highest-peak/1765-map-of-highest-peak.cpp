class Solution {
public:
    bool valid(int i,int j ,int m,int n){
    if(i>m-1||j>n-1||j<0||i<0)return false;
    return true;
}
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
         int m=isWater.size();
        int n=isWater[0].size();
          int level=0;
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]==1){
                    q.push({i,j});
                    isWater[i][j]=0;
                }
                else isWater[i][j]=-1;
            }
        }
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto [r,c]=q.front();
                q.pop();
               if(valid(r-1,c,m,n)&&isWater[r-1][c]==-1){
                q.push({r-1,c});
                isWater[r-1][c]=level+1;
               }
                if(valid(r,c+1,m,n)&&isWater[r][c+1]==-1){
                q.push({r,c+1});
                isWater[r][c+1]=level+1;
               }
                if(valid(r,c-1,m,n)&&isWater[r][c-1]==-1){
                q.push({r,c-1});
                isWater[r][c-1]=level+1;
               }
                if(valid(r+1,c,m,n)&&isWater[r+1][c]==-1){
                q.push({r+1,c});
                isWater[r+1][c]=level+1;
               }
            }
            level++;
        }
        return isWater;
    }
};