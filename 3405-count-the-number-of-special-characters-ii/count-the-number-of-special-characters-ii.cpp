class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int> mp;
        unordered_map<int,int> check;
        int cnt=0;
        for(int i=0; i<word.size(); i++) {
            if(word[i] >= 'a' && word[i]<='z') {
               mp[word[i]]++;
                check[word[i]]=i;
              
            }
            // else {
            //     if(mp.count(tolower(word[i]))) {
                   
            //           mp[tolower(word[i])]++;
            //     }
            // }
        }
        for(int i=0; i<word.size(); i++) {
             if(word[i] >= 'a' && word[i]<='z') {
                mp[word[i]]--;
                if(mp[word[i]]==0) mp.erase(word[i]);
                 } 
                else {
                      char x=tolower(word[i]);
                      if(!mp.count(x) && check.count(x) && check[x]<i) {
                        cnt++;
                        check[x]=INT_MAX;
                      }
                      if(mp.count(x)) {
                        check[x]=INT_MAX;
                      }
                }

        }
        return cnt;
    }
};