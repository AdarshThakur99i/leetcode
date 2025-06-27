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
unordered_map<TreeNode*,int> mp;
    int check(TreeNode* node) {
       if(node==NULL) {
        return 0;
       }
       if(mp.count(node)) {
        return mp[node];
       }
         int take=node->val;
        if(node->left !=NULL) {
        take+=check(node->left->left);
        take+=check(node->left->right);
        }
       
        if(node->right!=NULL) {
            take+=check(node->right->left);
            take+=check(node->right->right);
        } 
        int nottake_left=check(node->left);
        int nottake_right=check(node->right);

        return mp[node]=max(take,nottake_left+nottake_right);
    }
    int rob(TreeNode* root) {
        return check(root);
 
    }
};