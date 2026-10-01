class Solution {
public:
    bool valid(int r,int c,int n){
        return r>=0&&r<n&&c>=0&&c<n;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>
        >pq;
        pq.push({grid[0][0],{0,0}});
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        visited[0][0]=true;
        while(!pq.empty()){ 
            int t=pq.top().first;
            auto [r,c]=pq.top().second;
            ans=max(ans,t);
            if(r==n-1&&r==c)return ans;
            pq.pop();
            if(valid(r+1,c,n)&&!visited[r+1][c])pq.push({grid[r+1][c],{r+1,c}}),visited[r+1][c]=true;
            if(valid(r,c-1,n)&&!visited[r][c-1])pq.push({grid[r][c-1],{r,c-1}}),visited[r][c-1]=true;
            if(valid(r-1,c,n)&&!visited[r-1][c])pq.push({grid[r-1][c],{r-1,c}}),visited[r-1][c]=true;
            if(valid(r,c+1,n)&&!visited[r][c+1])pq.push({grid[r][c+1],{r,c+1}}),visited[r][c+1]=true;
            
        }
        return ans;
    }
};