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
     TreeNode* check(vector<int>& preorder ,int &l,int &r) {
        if(l==preorder.size() || preorder[l]>r) return NULL;
        TreeNode* node=new TreeNode(preorder[l++]);
        node->left=check(preorder,l,node->val);
        node->right=check(preorder,l,r);
        

        return node;
     }
    TreeNode* bstFromPreorder(vector<int>& preorder) {


        int r=INT_MAX;
        int l=0;
        return check(preorder,l,r);
             
    }
};