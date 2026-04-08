class Solution {
  public:
    void toposort(int src, vector<vector<pair<int,int>>> &adj,
                  vector<bool> &visited, stack<int> &st){
        visited[src] = true;

        for(auto v : adj[src]){
            if(!visited[v.first]){
                toposort(v.first, adj, visited, st);
            }
        }
        st.push(src);
    }

    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            
            adj[u].push_back({v,w}); // ✅ directed only
        }

        vector<bool> visited(V,false);
        stack<int> st;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                toposort(i, adj, visited, st);
            }
        }

        vector<int> dist(V,INT_MAX);
        dist[0] = 0;
        
        while(!st.empty()){
            int u = st.top();
            st.pop();
            
            if(dist[u] != INT_MAX) {
                for(auto v : adj[u]){
                    int node = v.first;
                    int wt = v.second;
                    
                    if(dist[node] > dist[u] + wt){
                        dist[node] = dist[u] + wt;
                    }
                }
            }
        }

        for(int i=0;i<V;i++){
            if(dist[i]==INT_MAX){
                dist[i] = -1;
            }
        }

        return dist;
    }
};