class Solution {
  public:
    void dijkstra(int src, vector<vector<pair<int,int>>> &adj,vector<int> &dist){
        dist[src]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,src});
        
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            for(auto v : adj[node]){
                int adjNode= v.first;
                int wt=v.second;
                
                if(dist[adjNode] > dis+wt){
                    dist[adjNode]=dis+wt;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        
    }
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        vector<vector<pair<int,int>>> adj(V);
        
        for(auto &e : edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        vector<int> dist(V,INT_MAX);
        dijkstra(src,adj,dist);
        
        return dist;
        
        
    }
};