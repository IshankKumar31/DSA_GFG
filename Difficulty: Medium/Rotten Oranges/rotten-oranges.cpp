class Solution {
public:
    int orangesRot(vector<vector<int>>& mat) {
        typedef pair<int,pair<int,int>> p;
        queue<p> q1;
        int n=mat.size();
        int m=mat[0].size();
        int fresh=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==2){
                    q1.push({0,{i,j}});
                }
                if(mat[i][j]==1){
                    fresh++;
                }
            }
        }

        vector<int> di ={-1,1,0,0};
        vector<int> dj= {0,0,-1,1};
        int mini=0;

        while(!q1.empty()){
            auto it= q1.front();
            q1.pop(); // (also good practice to pop)

            int t= it.first;
            int i=it.second.first;
            int j=it.second.second;
            mini=t;

            for(int k=0;k<4;k++){
                int ni= i+di[k];
                int nj= j+dj[k]; // FIXED

                if(ni>=0 && ni<n && nj>=0 && nj<m && mat[ni][nj]==1){
                    mat[ni][nj]=2;
                    fresh--;
                    q1.push({t+1,{ni,nj}});
                }
            }
        }

        if(fresh>0) return -1;
        return mini;
    }
};