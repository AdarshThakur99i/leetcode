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

vector<TreeNode*> trees(int start,int end) {
           if(start>end) {
            return {NULL};
           }

           if(start==end) {
             TreeNode* root=new TreeNode(start);
             return {root};
           }
           vector<TreeNode*> res;

           for(int i=start; i<=end; i++) {

            vector<TreeNode*>  left_bsts=trees(start,i-1);
            vector<TreeNode*> right_bsts=trees(i+1,end);

            for(TreeNode* leftRoot: left_bsts) {

                for(TreeNode* rightroot: right_bsts) {

                    TreeNode* root=new TreeNode(i);

                    root->left=leftRoot;
                    root->right=rightroot;

                    res.push_back(root);
                }
            }
           }

           return res;
     


}
    vector<TreeNode*> generateTrees(int n) {
        
       
       vector<vector<TreeNode*>> ans;

      return trees(1,n);

    
       
        
    }
};