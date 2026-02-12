class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n=arr.size();
        stack<pair<int,int>> st;
        vector<int> ans(n);
        
        for(int i=0;i<n;i++){
            int curr=1;
            while(!st.empty() && st.top().first<=arr[i]){
                curr+=st.top().second;
                st.pop();
            }
            
            st.push({arr[i],curr});
            ans[i]= curr;
        }
        return ans;
    }
};