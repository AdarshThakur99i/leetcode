class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
          unordered_set<string> st;
          for(int i=0; i<bank.size(); i++) {
            st.insert(bank[i]);
          } 
          queue<string> q;
          int cnt=0;
          q.push(startGene);
          while(!q.empty()) {
             
                int sz=q.size();
             
     for(int i=0; i<sz; i++) {
           string word=q.front();
           q.pop();
           for(int i=0; i<word.size(); i++) {
            char t=word[i];
            for(char j: {'A','C','G','T'}) {
          word[i]=j;
          if(st.find(word) != st.end()) {
            st.erase(word);
            q.push(word);
          
          if(word==endGene) {
            return cnt+1;
          }
           }
            }
           word[i]=t;
     }
     
     }   cnt++; }
     return -1;
    }
};