/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void check(TreeNode* Node,string &temp) {
        if(Node==NULL) return;      
        temp+=(to_string(Node->val));
        if(Node->right!=NULL && Node->left==NULL) {
            temp+="()(";
            check(Node->right,temp);
            temp+=')';
        }
        else {
            if(Node->left) {
                temp+='(';
        check(Node->left,temp);
        temp+=')';
            }
        if(Node->right) {
        temp+='(';
        check(Node->right,temp);
        temp+=')';}}
    }
    string tree2str(TreeNode* root) {
        string temp="";
        check(root,temp);
        return temp;
        
    }
};