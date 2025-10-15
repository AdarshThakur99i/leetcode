class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string,int> mp;
        string s="";
        int maxi=INT_MIN;
        string maxstr="";
        for(int i=0; i<word.size(); i++) {
            s+=word[i];
            if(s.size()==k) {
                mp[s]++;
             if(mp[s]>maxi) {
                maxi=max(maxi,mp[s]);
                maxstr=s;

            }
                   s="";
            }
           
            
        }
        s="";
        int cnt=0;
        for(int i=0; i<word.size(); i++) {
                 s+=word[i];
                 if(s.size()==k) {
                    if(s != maxstr) {
                         cnt++;
                    }
                    s="";
                 }
        }
        return cnt;
    }
};