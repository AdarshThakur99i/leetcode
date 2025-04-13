/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
Node* getNext(Node* node) {
      while(node) {

        if(node->left) return node->left;
        if(node->right) return node->right;
        node=node->next;
      }
      return nullptr;



}

   void dfs(Node* root) {

    if(root==NULL) return;

     

     if(root->left) {
        if(root->right) {
            root->left->next=root->right;
        }

        else {
            root->left->next=getNext(root->next);
        }

      
     }

     if(root->right) {
        root->right->next=getNext(root->next);
     }



      

     dfs(root->right);
     dfs(root->left);
        
   }
    Node* connect(Node* root) {

        dfs(root);
        return root;
        
    }
};