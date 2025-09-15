class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_map<char,int> mp;
        for(int i=0; i<brokenLetters.size(); i++) {
            mp[brokenLetters[i]]++;
        }
        int cnt=0;
        stringstream ss(text);
        string word;

        while(ss >> word) {
            bool ok=true;
                 for(int i=0; i<word.size(); i++) {
                      if(mp.count(word[i])) {
                        ok=false;
                        break;
                       }
                 }
                 if(ok) cnt++;
        }
        return cnt;
    }
};