class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        int n=adj.size();
        vector<int> ans;
        vector<bool> visited(n,false);
        queue<int> q1;
        q1.push(0);
        visited[0]=true;
        while(!q1.empty()){
            int u=q1.front();
            q1.pop();
            
            ans.push_back(u);
            for(int v : adj[u]){
                if(!visited[v]){
                    visited[v]=true;
                    q1.push(v);
                }
            }
        }
        return ans;
        
        
    }
};