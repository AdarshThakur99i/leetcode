class Solution {
public:
    string lastNonEmptyString(string s) {
        unordered_map<char,int> mp;
        for(int i=0; i<s.size(); i++) {
            mp[s[i]]++;
        }

        string temp="";
        int maxi=INT_MIN;
        for(auto it: mp) {
            maxi=max(maxi,it.second);
        }
           for(auto it: mp) {
            if(it.second==maxi) {
                temp+=it.first;
            }
        }

      unordered_map<char,int> mp2;
        for(int i=0; i<temp.size(); i++) {
            mp2[temp[i]]++;
        }
        string newt="";
    
        for(int i=0; i<s.size(); i++) {
            if(mp[s[i]]==1 && mp2.count(s[i])) {
                newt+=s[i];
            } 
              mp[s[i]]--;
        }
        return newt;
    }
};