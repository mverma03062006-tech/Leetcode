class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long ,long long >>>graph(n);
        for(auto road:roads){
            graph[road[0]].push_back({road[1],road[2]});
            graph[road[1]].push_back({road[0],road[2]});
        }
        priority_queue<pair<long long,long long>,vector<pair<long long,long long >>,greater<pair<long long,long long>>>minheap;
        minheap.push({0,0});
        vector<long long>ways(n,0);
        ways[0]=1;
        vector<long long>dist(n,LONG_MAX);
        dist[0]=0; 
        int MOD=1e9+7;
        while(!minheap.empty()){
            auto[d,u]=minheap.top();
            minheap.pop();
            if(d>dist[u])continue;
            for(auto[v,time]:graph[u]){
                if(dist[v]>d+time){
                    dist[v]=d+time;
                    ways[v]=ways[u];
                    minheap.push({dist[v],v});
                }
                else if(dist[v]==d+time)ways[v]=(ways[v]+ways[u])%MOD;
            }
        }
        return ways[n-1];
    }
};