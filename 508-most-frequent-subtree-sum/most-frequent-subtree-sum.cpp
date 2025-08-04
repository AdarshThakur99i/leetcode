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
     unordered_map<int,int> mp;
public:
    int check(TreeNode* node) {
          if(node==NULL) return 0;
          int res=0;
          res+=node->val;
          res+=check(node->left);
          res+=check(node->right);
          mp[res]++;
          return res;  
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
       int maxi=INT_MIN;
       check(root);
           for(auto it: mp) {
            maxi=max(maxi,it.second);

           }vector<int> ans;
           for(auto it: mp) {
            if(maxi==it.second) {
        ans.push_back(it.first);
            }
           }
           return ans;
    }
};