class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int i=0;
        int j=0;
        unordered_map<char,int> mp;
        unordered_map<char,int> mp2;
        for(int i=0; i<p.size(); i++) {
             mp[p[i]]++;
        }
        while(j<s.size()) {
           
            mp2[s[j]]++;
            while(j-i+1 > p.size()) {
                mp2[s[i]]--;
                if(mp2[s[i]]==0) mp2.erase(s[i]);
                i++;
              }
              if(j-i+1 == p.size() && mp2==mp) ans.push_back(i);
           
           j++;        
        }
        return ans;
    }
};