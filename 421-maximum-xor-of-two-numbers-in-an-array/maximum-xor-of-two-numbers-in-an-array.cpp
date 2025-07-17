class Solution {
public:
    struct trieNode {
        trieNode *left;
        trieNode *right;
    };

    void insert(int num,trieNode* root) {
       trieNode* pcrawl=root; 
         for(int i=31; i>=0; i--) {
          
            int ithbit=(num>>i)&1;

            if(ithbit==0) {
                if(pcrawl->left==NULL) {
                    pcrawl->left=new trieNode();
                }
                pcrawl=pcrawl->left;

            }
            else {
                if(pcrawl->right==NULL) {
                    pcrawl->right=new trieNode();

                }
                pcrawl=pcrawl->right;
            }
        }
    }
    int maxOr(trieNode* root,int nums) {
           int xore=0;
           trieNode* p=root;
           for(int i=31; i>=0; i--) {
              int ithbit=(nums>>i) & 1;
              if(ithbit==1) {
                if(p->left) {
              xore +=pow(2,i);
                    p=p->left;
                }
                else {
                    p=p->right;
                }

                
              }
              else {
                 if(p->right) {
              xore +=pow(2,i);
                    p=p->right;
                }
                else {
                    p=p->left;
                }
              }
           }
           return xore;
    }
    int findMaximumXOR(vector<int>& nums) {
        trieNode* root=new trieNode();
        for(int i=0; i<nums.size(); i++) {
            insert(nums[i],root);
        }
        int maxi=INT_MIN;
        for(int i=0; i<nums.size(); i++) {
            int res=maxOr(root,nums[i]);
          maxi=max(maxi,res);
        }
         return maxi;
    }
};