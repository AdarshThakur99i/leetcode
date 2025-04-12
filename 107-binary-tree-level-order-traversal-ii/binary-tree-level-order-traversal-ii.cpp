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

    void dfs(TreeNode* root,vector<vector<int>> &ans,int k) {
          if(root==NULL) return;
if(ans.size()<=k) {
    ans.push_back({});
}
          ans[k].push_back(root->val);
          dfs(root->left,ans,k+1);
          dfs(root->right,ans,k+1);





    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
  
        vector<vector<int>> ans;

        dfs(root,ans,0);

      reverse(ans.begin(),ans.end());

        return ans;
        
    }
};