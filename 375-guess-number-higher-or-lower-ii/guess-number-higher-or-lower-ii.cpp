class Solution {
public:
    int check(int start,int end,vector<vector<int>> &dp) {
        
          if(start>=end) {
            return 0;
          }
          if(dp[start][end]!=-1) return dp[start][end];
          int res=INT_MAX;
          
       for(int i=start; i<=end; i++) {
            int take1=i + max(check(i+1,end,dp), check(start,i-1,dp));
           res=min(res,take1);
       }

       return dp[start][end]=res;
    }
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return check(1,n,dp);
        
    }
};