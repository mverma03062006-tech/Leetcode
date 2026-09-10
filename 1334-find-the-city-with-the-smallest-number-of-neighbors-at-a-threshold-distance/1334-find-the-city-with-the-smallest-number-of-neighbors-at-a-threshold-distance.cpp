class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        int ans=-1,mincount=n;
        for(int i=0;i<n;i++){
            int start=i;
            vector<int>dist(n,INT_MAX);
            dist[start]=0;
             priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
            pq.push({0,start});
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
        int cnt=0;
        for(int j=0;j<n;j++){
            if(dist[j]<=distanceThreshold)cnt++;
        }
        if(cnt<=mincount){
            mincount=cnt;
            ans=i;
        }
        }
        return ans;
    }
};