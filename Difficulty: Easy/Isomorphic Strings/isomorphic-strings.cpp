class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        // code here
        int n1=s1.size();
        int n2=s2.size();
        
        if(n1 != n2)return false;
        
        int mapS1[256]={0};
        int mapS2[256]={0};
        
        for(int i=0;i<n1;i++){
            if(mapS1[s1[i]] != mapS2[s2[i]]){
                return false;
            }
            
            mapS1[s1[i]]=i+1;
            mapS2[s2[i]]=i+1;
        }
        return true;
    }
};