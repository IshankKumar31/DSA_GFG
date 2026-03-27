class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto &e :edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
        }
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto v :adj[i]){
                indegree[v]++;
            }
        }
        
        queue<int> q1;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q1.push(i);
            }
        }
        vector<int> ans;
        while(!q1.empty()){
            int node=q1.front();
            q1.pop();
            ans.push_back(node);
            for(auto v:adj[node]){
                indegree[v]--;
                if(indegree[v]==0){
                    q1.push(v);
                }
            }
        }
        return ans;
        
    }
};