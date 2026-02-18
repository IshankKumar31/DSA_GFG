class Solution {
  public:
    int findCeil(Node* root, int x) {
        // code here
        int ans=-1;
        
        while(root != NULL){
            if(root->data>=x){
                ans=root->data;
                root=root->left;
            }
            // if(root->data > x){
            //     ans=root->data;
            //     root=root->left;
            else{
                root=root->right;
            }
        }
        return ans;
    }
};
