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
      int max_d=0;
     void solve(TreeNode* node,int d,unordered_map<int,int> &mp) {
               if(node==NULL) return;
              max_d=max(max_d,d);
               mp[node->val]=d;
               solve(node->left,d+1,mp);

               solve(node->right,d+1,mp);
     }

     TreeNode* solve2(TreeNode* node,unordered_map<int,int> &mp) {
              
               if(node==NULL ||  mp[node->val]==max_d ) return node; 
              

              
               TreeNode* left=solve2(node->left,mp);
              TreeNode* right=solve2(node->right,mp);
 if(left !=NULL && right!=NULL) {
                return node;
               }
               return (left==NULL)?right:left;
          
     }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        unordered_map<int,int> mp;
        int d=0;
        mp[root->val]=0;
        solve(root,d,mp);
        return solve2(root,mp);

        

    }
};