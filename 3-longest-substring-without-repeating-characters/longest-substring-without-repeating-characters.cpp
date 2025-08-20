class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi=0;
        unordered_map<char,int> mp;
      int i=0;
      int j=0;
      while(j<s.size()) {
mp[s[j]]++;
        if(mp[s[j]]>1) {
            while(mp[s[j]] !=1) {
                mp[s[i]]--;
                i++;

            }
        }
        maxi=max(maxi,(j-i+1));
        j++;
      }
        return maxi;
    }
};