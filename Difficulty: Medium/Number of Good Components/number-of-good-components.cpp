class Solution {
public:
    void dfs(int start, vector<vector<int>> &adj, vector<bool> &visited, int &edges, int &vertices){
        visited[start] = true;
        vertices++;
        
        edges += adj[start].size();
        
        for(auto v : adj[start]){
            if(!visited[v]){
                dfs(v, adj, visited, edges, vertices);
            }
        }
    }

    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edgesList) {
        vector<vector<int>> adj(v);
        
        for(auto &e : edgesList){
            int u = e[0]-1;
            int v2 = e[1]-1;
            
            adj[u].push_back(v2);
            adj[v2].push_back(u);
        }

        vector<bool> visited(v, false);
        int count = 0;

        for(int i = 0; i < v; i++){
            if(!visited[i]){
                int edges = 0;
                int vertices = 0;
                
                dfs(i, adj, visited, edges, vertices);
                
                edges /= 2;
                
                if(edges == (vertices * (vertices - 1)) / 2){
                    count++;
                }
            }
        }
        
        return count;
    }
};