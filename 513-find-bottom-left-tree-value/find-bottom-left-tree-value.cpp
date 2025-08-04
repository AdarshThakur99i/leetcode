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
    int maxLevel=INT_MIN;
    int val=-1;
public:
    void dfs(TreeNode* root,int level) {
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL) {
            if(level>maxLevel) {
                maxLevel=level;
                val=root->val;
            }
            return;
        }
        dfs(root->left,level+1);
        dfs(root->right,level+1);

    }
    int findBottomLeftValue(TreeNode* root) {
            dfs(root,0);
            return val;
    }
};