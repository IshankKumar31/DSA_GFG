/*Structure of the node of the binary tree is as


/*Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
*/
// function should return the sum of all
// right leaf nodes
class Solution {
  public:
    int rightLeafSum(Node* root) {
        
        if(root==NULL){
            return 0;
        }
        int sum=0;
        
        if(root->right != NULL && root->right->left ==NULL && root->right->right == NULL){
            sum+=root->right->data;
        }
        
        return sum+rightLeafSum(root->left)+rightLeafSum(root->right);
        
    }
};