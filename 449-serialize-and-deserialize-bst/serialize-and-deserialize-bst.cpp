/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
       
        string s="";
      build(s,root);
        return s;
          
    }
    void build(string &s,TreeNode* root) {
        if(root==NULL) return;
        s+=to_string(root->val) + ' ';
        build(s,root->left);
        build(s,root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
      vector<int> preorder;
      istringstream ss(data);
      int num;
      while(ss >> num) {
        preorder.push_back(num);
      }
      int idx=0;
      return calculate(preorder,idx,INT_MIN,INT_MAX);
    }
    TreeNode* calculate(vector<int> &preorder,int &idx,int lower,int upper) {
        if(idx>=preorder.size()) return nullptr;
        if(preorder[idx]<lower || preorder[idx]>upper) return nullptr;
        TreeNode* node=new TreeNode(preorder[idx]);
        int val=preorder[idx];
        idx++;
         node->left=calculate(preorder,idx,lower,val);
         node->right=calculate(preorder,idx,val,upper);

         return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;