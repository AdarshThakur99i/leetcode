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

    void dfs(TreeNode* root,vector<int> temp,  vector<vector<int>> &ans,int targetSum) {
         if(root==NULL) {
          
        

              return;

         }
 temp.push_back(root->val);

 if(root->left==NULL && root->right==NULL && targetSum-root->val==0) {
ans.push_back(temp);
 }

        
         dfs(root->left,temp,ans,targetSum-root->val);
      
         dfs(root->right,temp,ans,targetSum-root->val);
  temp.pop_back();
 


    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        vector<vector<int>> ans;
        int sum=0;
        dfs(root,temp,ans,targetSum);

        return ans;
    }
};