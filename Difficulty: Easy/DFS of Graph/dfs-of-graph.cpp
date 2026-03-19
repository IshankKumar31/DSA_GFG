class Solution {
  public:
    void dfsHelper(int u,vector<vector<int>> &adj,vector<bool>& visited,vector<int> &ans){
        visited[u]=true;
        ans.push_back(u);
        
        for(int v : adj[u]){
            if(!visited[v]){
                dfsHelper(v,adj,visited,ans);
            }
        }
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        int n=adj.size();
       
        vector<bool> visited(n,false);
        vector<int> ans;
        
        dfsHelper(0,adj,visited,ans);
        
        return ans;
        
    }
};