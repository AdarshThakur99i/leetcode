class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> mp;
        for(int i=0; i<s.size(); i++) {
            mp[s[i]]++;
        }
        int maxc=INT_MIN;
        int even=INT_MAX;
        int odd=INT_MIN;
        for(auto x:mp) {
            if(x.second%2==0) even=min(even,x.second);
            else odd=max(odd,x.second);
           if(even!=INT_MAX && odd!=INT_MIN) maxc=max(odd-even,maxc);
            
       
        }
        if(mp.size()==1) return mp[s[0]];
        
        return maxc;
        
    }
};