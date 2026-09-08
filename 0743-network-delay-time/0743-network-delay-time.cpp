class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto x:times){
            adj[x[0]].push_back({x[1], x[2]});
        }
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        while(!pq.empty()){
            auto [d,node]=pq.top();
            pq.pop();

            if(dist[node]<d)continue;

            for(auto [v,weight]:adj[node]){
                if(d+weight<dist[v]){
                    dist[v]=d+weight;
                    pq.push({dist[v],v});
                }
            }
        }
        int ans=*max_element(dist.begin()+1,dist.end());
        if(ans==INT_MAX)return -1;
        return ans;
    }
};