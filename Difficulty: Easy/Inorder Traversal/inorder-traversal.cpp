/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  
    void traversal(Node* root, vector<int> &result){
        if(root==0){
            return;
        }
        
        traversal(root->left,result);
        result.push_back(root->data);
        traversal(root->right,result);
    }
    vector<int> inOrder(Node* root) {
        vector<int> result;
        
        traversal(root,result);
        
        return result;
        
    }
};