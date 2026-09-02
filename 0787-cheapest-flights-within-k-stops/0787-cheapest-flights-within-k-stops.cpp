class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>>q;
        vector<int>dist(n,INT_MAX);
        q.push({0,{src,0}});
        dist[src]=0;
    
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            if(stops>k)continue;

            for(auto nei:adj[node]){
                int adjNode=nei.first;
                int newcost=nei.second;
                if(newcost+cost<=dist[adjNode]&&stops<=k){
                    dist[adjNode]=cost+newcost;
                    q.push({stops+1,{adjNode,cost+newcost}});
                }
            }
        }
        if(dist[dst]==INT_MAX)return -1;
        return dist[dst];
    }
};