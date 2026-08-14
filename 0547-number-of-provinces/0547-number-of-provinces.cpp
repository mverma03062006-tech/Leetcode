class Solution {
public:
void dfs(vector<int>adj[],vector<int> &visited,int i){
    visited[i]=1;
    for(auto it:adj[i]){
        if(!visited[it]){
        dfs(adj,visited,it);
    }}
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected[0].size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j&&isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int>visited(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
            dfs(adj,visited,i);
            }
        }
        return count;
    }
};