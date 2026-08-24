class Solution {
public:
    bool dfs(int i,vector<vector<int>>&adj,vector<int>& vis,vector<int>& path,vector<int>& ans){
        vis[i]=1;
        path[i]=1;
        for(auto it:adj[i]){
            if(!vis[it]){
                if(dfs(it,adj,vis,path,ans)){
                    return true;
                }
            }
            else if(path[it])return true;
        }
        path[i]=0;
        ans.push_back(i);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
         int n=numCourses;
        vector<vector<int>>adj(n);
        for(int i=0;i<pre.size();i++){
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        vector<int>ans;
        vector<int>vis(n,0);
        vector<int>path(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,path,ans))return {};
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};