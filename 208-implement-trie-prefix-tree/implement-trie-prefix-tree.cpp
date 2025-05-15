class Trie {
public:

struct trieNode {
      bool isEnd;
      trieNode* children[26];
};

trieNode* getNode() {
        trieNode* node=new trieNode();
        node->isEnd=false;
        for(int i=0; i<26; i++) {
            node->children[i]=NULL;
        }

        return node;

}

  trieNode* root;

    Trie() {
        root=getNode();
        
    }
    
    void insert(string word) {
        trieNode* crawler=root;

        for(int i=0; i<word.size(); i++) {
          int idx=word[i]-'a';
          if(crawler->children[idx]==NULL) {
            crawler->children[idx]=getNode();

          }
          crawler=crawler->children[idx];


        }
  

  crawler->isEnd=true;
        
    }
    
    bool search(string word) {
        trieNode* crawler=root;
        for(int i=0; i<word.size(); i++) {
               int idx=word[i]-'a';
               if(crawler->children[idx]==NULL) {
                return false;
               }

               crawler=crawler->children[idx];

        }

        if(crawler!=NULL && crawler->isEnd==true) {
            return true;
        }
        return false;
        
    }
    
    bool startsWith(string prefix) {
       trieNode* crawler=root;
       int i=0;
       for( i=0; i<prefix.size(); i++) {
        int idx=prefix[i]-'a';
             if(crawler->children[idx]==NULL) {
                return false;
             }

crawler=crawler->children[idx];
          

       }   if(i==prefix.size()) {
                return true;
             }
       return false;

    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */