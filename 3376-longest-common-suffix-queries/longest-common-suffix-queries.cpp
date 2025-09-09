class trieNode {
      public:
      trieNode* children[26];
      int bestIdx;
       trieNode() {
      for(int i=0; i<26; i++) {
        children[i]=nullptr;
      }
      bestIdx=-1;}
};
class Node {
    private:
    trieNode* node;
  
    public:
    Node() {
     node=new trieNode();
   
    }

    void insert(string &x,vector<string>& words,int idx,int &maxQueryLen) {
        trieNode* root=node;
  if(root->bestIdx==-1 || 
       words[idx].size() < words[root->bestIdx].size() || 
       (words[idx].size() == words[root->bestIdx].size() && idx < root->bestIdx)) {
        root->bestIdx = idx;
    }

        for (int i = x.size() - 1, depth = 1; i >= 0 && depth <= maxQueryLen; i--, depth++) {
            int c=x[i]-'a';
           if(root->children[c]==nullptr) {
            root->children[c]=new trieNode();
           }
           root=root->children[c];

           if(root->bestIdx==-1 || words[idx].size()<words[root->bestIdx].size() || (words[idx].size()==words[root->bestIdx].size() && idx<root->bestIdx)) {
            root->bestIdx=idx;
           }
        }


    }
    int query(string &word) {
        trieNode* root=node;
        for(int i=word.size()-1; i>=0; i--) {
            int idx=word[i]-'a';
            if(!root->children[idx]) break;
            root=root->children[idx];
        }

        return root->bestIdx;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
Node trie; 
int maxi=INT_MIN;
for(int i=0; i<wordsQuery.size(); i++) {
    int temp=wordsQuery[i].size();
    maxi=max(maxi,temp);
}
             for(int i=0; i<wordsContainer.size(); i++ ) {
               trie.insert(wordsContainer[i],wordsContainer,i,maxi);
             }

vector<int> ans;
             for(int i=0; i<wordsQuery.size(); i++) {
                ans.push_back(trie.query(wordsQuery[i]));
             }
             return ans;
    }
};