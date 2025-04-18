class Solution {
public:

     bool check(string &s,vector<string> &wordDict,unordered_map<string,bool> &mp,int i,vector<int> &dp) {

if(i==s.size()) return true;
        

     if(dp[i]!=-1) return dp[i];
     
        for(int j=i+1; j<=s.size(); j++) {

            string p=s.substr(i,j-i);
            
            if(mp[p]==true &&    check(s,wordDict,mp,j,dp)) {
                
              return dp[i]=true;
            }
        }
    

        return dp[i]=false;
     }
    bool wordBreak(string s, vector<string>& wordDict) {
         unordered_map<string,bool> mp;
         vector<int> dp(s.size(),-1);
         for(int i=0; i<wordDict.size(); i++) {

            mp[wordDict[i]]=true;
         }
        return check(s,wordDict,mp,0,dp);
    }
};