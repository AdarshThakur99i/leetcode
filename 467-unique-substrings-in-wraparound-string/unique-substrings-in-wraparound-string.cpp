class Solution {
public:
    int findSubstringInWraproundString(string s) {
        if(s.size()==1) return 1;
        int cnt=0;
       vector<int> dp(27,0);
       for(int i=0; i<s.size(); i++) {
        if(i>0 && (s[i]==(s[i-1]+1) || (s[i-1]=='z' && s[i]=='a'))) {
            cnt++;
        }
        else {
            cnt=1;
        }
        dp[s[i]-'a']=max(dp[s[i]-'a'],cnt);
       }
      cnt=0;
         for(int i=0; i<dp.size(); i++) {
             cnt+=dp[i];
         }
         return cnt;
    }
};

//a f r e s e