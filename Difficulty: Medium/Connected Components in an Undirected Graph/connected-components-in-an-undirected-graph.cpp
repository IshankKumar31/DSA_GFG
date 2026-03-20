class Solution {
  public:
  
    void dfs(int start,vector<vector<int>> &adj,vector<bool> &visited,vector<int> &comp){
        visited[start]=true;
        comp.push_back(start);
        
        for(int v : adj[start]){
            if(!visited[v]){
                dfs(v,adj,visited,comp);
            }
        }
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        
        for(auto &e : edges){
            int u= e[0];
            int v= e[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(V,false);
        vector<vector<int>> ans;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                vector<int> comp;
                dfs(i,adj,visited,comp);
                ans.push_back(comp);
            }
        }
        
        return ans;
        
        
    }
};
