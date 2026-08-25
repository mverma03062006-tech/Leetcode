class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>ans;
        vector<int>out(graph.size());
        int n=graph.size();
        vector<vector<int>>rev(n);
        for(int i=0;i<graph.size();i++){
            out[i]=graph[i].size();
             for(auto it : graph[i]) {
                rev[it].push_back(i);   
            }
        }
        queue<int>q;
        for(int i=0;i<graph.size();i++){
            if(out[i]==0)q.push(i);
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : rev[node]) { 
                out[it]--;

                if(out[it] == 0)
                    q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};