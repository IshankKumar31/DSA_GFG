class Solution {
  public:
  
    bool dfs(int curr,vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &rec){
        visited[curr]=true;
        rec[curr]=true;
        
        for(int v : adj[curr]){
            if(!visited[v]){
                if(dfs(v,adj,visited,rec)){
                    return true;
                }
            }
            else if(rec[v]){
                return true;
            }
        }
        rec[curr]=false;
        return false;
        
        
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto &e : edges){
            int u=e[0];
            int v=e[1];
            
            adj[u].push_back(v);
           
        }
        vector<bool> visited(V,false);
        vector<bool> rec(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(i,adj,visited,rec))return true;
            }
        }
        return false;
    }
};