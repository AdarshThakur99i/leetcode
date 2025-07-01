class Solution {
public:
    int possibleStringCount(string word) {
        int cnt=1;
        unordered_map<int,int> mp;
        for(int i=1; i<word.size(); i++) {
            if(word[i]==word[i-1]) {
          
            cnt++;
           }
           
           }          
               return cnt;
    }
};