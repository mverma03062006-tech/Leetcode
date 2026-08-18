class Solution {
public:
    bool dfs(int i,vector<vector<int>>& adj,vector<int>& visited){
        if(visited[i]==1)return false;
        if(visited[i]==2)return true;
        visited[i]=1;

        for(int  next: adj[i]){
            if(!dfs(next,adj,visited))return false;
        }
        visited[i]=2;
        return true;

    }
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        int n=numCourses;
        vector<vector<int>>adj(n);
        for(int i=0;i<pre.size();i++){
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        vector<int>visited(n,0);
        for(int i=0;i<n;i++){
            if(!dfs(i,adj,visited)){
                return false;
            }
        }
        return true;
    }
};