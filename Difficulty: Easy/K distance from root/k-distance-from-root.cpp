/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution {
  public:
    // function should print the nodes at k distance from root
    vector<int> Kdistance(Node *root, int k) {
        
        if(root==NULL){
            return {};
        }
        
        queue<Node*> q1;
        q1.push(root);
        int l=0;
        while(!q1.empty()){
            vector<int> level;
            int size = q1.size();
            for(int i=0;i<size;i++){
                Node* curr= q1.front();
                q1.pop();
                
                level.push_back(curr->data);
                
                if(curr->left != NULL) q1.push(curr->left);
                if(curr->right != NULL) q1.push(curr->right);
            }
            if(l==k){
                return level;
            }
            
            l++;
            
        }
        return {};
        
    }
};