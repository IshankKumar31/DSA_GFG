class Solution {
  public:
    void bfs(int src,vector<vector<int>> &adj,vector<int> &dist){
        queue<int> q1;
        q1.push(src);
        dist[src]=0;
        
        while(!q1.empty()){
            int u= q1.front();
            q1.pop();
            
            for(auto v : adj[u]){
                if(dist[v]==INT_MAX){
                    dist[v]=dist[u]+1;
                    q1.push(v);
                }
            }
        }
        
    }
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        vector<vector<int>> adj(V);
        
        for(auto &e :edges){
            int u=e[0];
            int v=e[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }
        vector<int> dist(V,INT_MAX);
        bfs(src,adj,dist);
        
        
        for(int i=0;i<V;i++){
            if(dist[i]==INT_MAX){
                dist[i]=-1;
            }
        }
        return dist;
        
    }
};
