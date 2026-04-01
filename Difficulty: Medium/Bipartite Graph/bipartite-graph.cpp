class Solution {
  public:
    bool check(int start, vector<vector<int>>&adj, vector<int> &color){
        queue<int> q1;
        q1.push(start);
        color[start]=0;
        while(!q1.empty()){
            int v=q1.front();
            q1.pop();
            
            for(auto it : adj[v]){
                if(color[it]==-1){
                    color[it]= !color[v];
                    q1.push(it);
                }
                else if(color[it]==color[v]){
                    return false;
                }
            }
        }
        return true;
        
    }
    bool isBipartite(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        
        for(auto &e :edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> color(V,-1);
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(check(i,adj,color)==false){
                    return false;
                }
            }
        }
        return true;
            
        
        
    }
};