class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp;

        for (int i=0; i<s.size(); i++) {
            mp[s[i]]++;

        }
        unordered_map<char,int> mp2;
        for(int i=0; i<t.size(); i++) {
            if(mp[t[i]] >0) {
                mp2[t[i]]++;

            }
            else {
                return false;
            }
        }
        for(auto it : mp) {
            if(it.second != mp2[it.first]) {
                return false;
            }
        }
        return true;
    }
};