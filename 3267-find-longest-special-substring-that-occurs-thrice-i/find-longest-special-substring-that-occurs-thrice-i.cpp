class Solution {
public:

    bool check(string x) {

        for(int i=0; i<x.size(); i++) {
            if(i+1 < x.size() && x[i]!=x[i+1]){
                return false;
                
            }
        }
        return true;
    }
    int maximumLength(string s) {
int maxi=INT_MIN;
        unordered_map<string,int> mp;
        for(int i=0; i<s.size(); i++) {
            for(int j=i; j<s.size(); j++) {
                string temp=s.substr(i,(j-i+1));
                if(check(temp)) {
                mp[temp]++;
                if(mp[temp]>=3) {
                   maxi=max(maxi,(j-i+1));
                }
                }
            }
        }

        return (maxi==INT_MIN) ? -1:maxi;
    }
};