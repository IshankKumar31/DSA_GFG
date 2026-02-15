/* A binary tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> ans;
        
        queue<Node*> q1;
        q1.push(root);
        
        while(!q1.empty()){
            int size=q1.size();
            vector<int> level;
            for(int i=0;i<size;i++){
                Node* curr= q1.front();
                q1.pop();
                level.push_back(curr->data);
                
                if(curr->left != NULL){
                    q1.push(curr->left);
                }
                if(curr->right != NULL){
                    q1.push(curr->right);
                }
            }
            ans.push_back(level);
        }
        
        return ans;
        
    }
};