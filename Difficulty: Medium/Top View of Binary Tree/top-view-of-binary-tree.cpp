/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        
    vector<int> result;
    
    if(root==NULL){
        return result;
    }
    
    map<int,int> topNode;
    queue<pair<Node*,int>> q1;
    q1.push(make_pair(root,0));
    
    while(!q1.empty()){
        pair<Node*,int> frontVal = q1.front();
        q1.pop();
        
        Node* node= frontVal.first;
        int hd= frontVal.second;
        
        if(topNode.find(hd)==topNode.end()){
            topNode[hd]= node->data;
        }
        if(node->left != NULL) q1.push(make_pair(node->left,hd-1));
        if(node->right != NULL) q1.push(make_pair(node->right,hd+1));
    }
    
    for(auto it : topNode){
        result.push_back(it.second);
    }
    return result;
        
    }
};