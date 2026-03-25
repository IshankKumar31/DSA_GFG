class Solution {
  public:
    void dfs(int start,vector<vector<int>> &adj,vector<bool> &visited,stack<int> &st){
        visited[start]=true;
        for(int v : adj[start]){
            if(!visited[v]){
                dfs(v,adj,visited,st);
            }
        }
        st.push(start);
    }
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto &e : edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
        }
        vector<bool> visited(V,false);
        stack<int> st;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,adj,visited,st);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
        
    }
};