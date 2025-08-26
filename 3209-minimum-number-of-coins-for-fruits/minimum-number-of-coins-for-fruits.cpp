class Solution {
public:
   int check(vector<int>& prices,int i,int idx,vector<vector<int>> &dp) {
             if(i==prices.size()) {
                return 0;
             }
             if(dp[i][idx]!=-1) return dp[i][idx];

            int takeforfree=INT_MAX;
            if((i != 0) && i<=idx ) {
             takeforfree=check(prices,i+1,idx,dp);
            }

            int takeformoney=prices[i]+check(prices,i+1,i+(i+1),dp);

            return dp[i][idx]=min(takeforfree,takeformoney);
   }
    int minimumCoins(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2*prices.size(),-1));
            return check(prices,0,0,dp);
    }
};