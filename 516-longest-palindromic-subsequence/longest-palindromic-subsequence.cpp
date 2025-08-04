class Solution {
public:

    int check(string &s,int i,int j,vector<vector<int>> &dp) {
         if(i>j) return 0;
       
         if(i==j) {
            return 1;
         }if(dp[i][j]!=-1) return dp[i][j];
         if(s[i]==s[j]) {
            return dp[i][j]=2+ check(s,i+1,j-1,dp);
         }
         else {
            return dp[i][j]=max(check(s,i+1,j,dp),check(s,i,j-1,dp));
         }
return 0;
    }
    int longestPalindromeSubseq(string s) {
      vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
   
        return check(s,0,s.size()-1,dp);
    }
};