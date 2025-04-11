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


   TreeNode* check(vector<int> &inorder,int si,int ei,vector<int> &postorder,int sp,int ep,unordered_map<int,int> &mp) {
        if(si>ei || sp>ep) return NULL;


        TreeNode* root=new TreeNode(postorder[ep]);

        int numleft=mp[postorder[ep]]-si;
        root->left=check(inorder,si,mp[postorder[ep]]-1,postorder,sp,sp+numleft-1,mp);
        root->right=check(inorder,mp[postorder[ep]]+1,ei,postorder,sp+numleft,ep-1,mp);


        return root;

   }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;

        for(int i=0; i<inorder.size(); i++) {
             mp[inorder[i]]=i;

        }

        return check(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mp);
    }
};