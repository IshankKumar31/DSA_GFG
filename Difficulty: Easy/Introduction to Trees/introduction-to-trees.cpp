// User function Template for C++

class Solution {
  public:
    int countNodes(int i) {
        // your code here
        int ans=1;
        for(int j=1;j<i;j++){
            ans*= 2;
        }
        return ans;
    }
};