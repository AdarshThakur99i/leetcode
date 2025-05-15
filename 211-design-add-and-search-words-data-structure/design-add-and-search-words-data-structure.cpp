class WordDictionary {
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
    WordDictionary() {
        root=getNode();



        
              
    }
    
    void addWord(string word) {

        trieNode* crawl=root;
        for(int i=0; i<word.size(); i++) {
            int idx=word[i]-'a';
            if(crawl->children[idx]==NULL) {
                crawl->children[idx]=getNode();
            }
            crawl=crawl->children[idx];
            
        }
        crawl->isEnd=true; 

        
            
    }
    bool dfs(trieNode* crawl,string word,int i) {
        if(i==word.size()) return crawl->isEnd;
   if(word[i]=='.') {
   for(int j=0; j<26; j++) {
    if(crawl->children[j]!=NULL && dfs(crawl->children[j],word,i+1)) {
        return true;
   
    }
   }
   return false;


   }
        int idx=word[i]-'a';

             if(crawl->children[idx]==NULL) {
                return false;
             }
            

 return dfs(crawl->children[idx],word,i+1);
         

    }
    
    bool search(string word) {
       trieNode* crawl=root;
      return dfs(crawl,word,0);
       
       

           
    }
};  

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */