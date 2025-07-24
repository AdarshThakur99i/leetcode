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
   int dfs(TreeNode* node,long long sum) {
        if(!node) return 0;
        long long res=0;
        if(node->val==sum) res++;
        res+=dfs(node->left,sum-(node->val));
        res+=dfs(node->right,sum-(node->val));

        return res;

   }
    int pathSum(TreeNode* root, int targetSum) {
          if(!root) return 0;

          return dfs(root,targetSum) + pathSum(root->left,targetSum)+pathSum(root->right,targetSum);
    }
};