class trieNode {
    public:
       bool isEnd;
       trieNode* children[10];

       trieNode() {
        isEnd=false;
        for(int i=0; i<10; i++) {
            children[i]=NULL;
        }
       }
};

class trie {
       private:
       trieNode* root;
       public:
       trie() {
         root=new trieNode();

       }
       void insert(int a) {
        trieNode* x=root;
        string s=to_string(a);
        for(auto it: s) {
         int idx=it-'0';
            if(x->children[idx]==nullptr) {
                    x->children[idx]=new trieNode();
            }
            x=x->children[idx];
        
       }
       x->isEnd=true;
       }
      int longestcommon(const string &s) {
        string prefix="";
        trieNode* x=root;
        int len=0;
      for(auto it:s) {
        int idx=it-'0';
        if(x->children[idx]!=nullptr) {
                 len++;
                 x=x->children[idx];
        }
        else {
            break;
        }
      }
      return len;
      }
       
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans=INT_MIN;
        trie t;
              for(int i=0; i<arr1.size(); i++) {
                    t.insert((arr1[i]));
              }
              for(int i=0; i<arr2.size(); i++) {
                ans=max(ans,t.longestcommon(to_string(arr2[i])));
              }
              return ans==INT_MIN ? 0:ans;
    }
};