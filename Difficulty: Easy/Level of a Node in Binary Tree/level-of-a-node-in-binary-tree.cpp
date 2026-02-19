/*
Structure of the node of the binary tree is
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
*/
class Solution {
  public:
    // function should return level of the target node
    int getLevel(struct Node *node, int target) {
        // code here
        int l=1;
        if(node==NULL){
            return l;
        }
        
        queue<Node*> q1;
        q1.push(node);
        
        while(!q1.empty()){
            int size=q1.size();
            
            for(int i=0;i<size;i++){
                Node* curr= q1.front();
                q1.pop();
                if(curr->data == target){
                    return l;
                }
                
                if(curr->left !=NULL)q1.push(curr->left);
                if(curr->right != NULL)q1.push(curr->right);
            }
            l++;
        }
        return 0;
    }
};