class Solution {
public:
 
    int maxPalindromesAfterOperations(vector<string>& words) {
            unordered_map<char,int> mp;
            for(int i=0; i<words.size(); i++) {
                for(int j=0; j<words[i].size(); j++) {
                    mp[words[i][j]]++;
                }
            }
            int pairs=0;
            for(auto it: mp) {
                pairs+=it.second/2;
            }
            vector<int> length;
            for(int i=0; i<words.size(); i++) {
                length.push_back(words[i].size());
            }
            sort(begin(length),end(length));
            int cnt=0;
   for(int i=0; i<length.size(); i++) {
                int len=length[i];
                int needed=len/2;
                pairs -= needed;
                if(pairs >=0 ) {
                    cnt++;
                }
            }
         return cnt;
   
    }
};