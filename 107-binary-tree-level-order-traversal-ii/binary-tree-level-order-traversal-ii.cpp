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

    void dfs(TreeNode* root,map<int,vector<int>,greater<int>> &mp,int k) {
          if(root==NULL) return;

          mp[k].push_back(root->val);
          dfs(root->left,mp,k+1);
          dfs(root->right,mp,k+1);





    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
      map<int,vector<int>,greater<int>> mp;
        vector<vector<int>> ans;
        dfs(root,mp,0);

        for(auto it: mp) {

ans.push_back(it.second);



        }

        return ans;
        
    }
};