class Trie {
public:
unordered_set<string> st;
    Trie() {
        st.clear();
    }
    
    void insert(string word) {
        st.insert(word);
        
    }
    
    bool search(string word) {
        if(st.find(word) !=st.end()) {
            return true;
        }
        
        return false;
    }
    
    bool startsWith(string prefix) {
      
      for(string x : st){
           
           if(x.size()<prefix.size()) {
            continue;
           }
            string ss=x.substr(0,prefix.size());
            if(ss==prefix) {
                return  true;
            }
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