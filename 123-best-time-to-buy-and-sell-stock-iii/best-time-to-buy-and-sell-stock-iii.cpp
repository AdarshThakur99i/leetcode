class Solution {
public:

    int check(vector<int> &prices,int i,int buy,int k,vector<vector<vector<int>>> &dp) {
        if(k>=2 || i>=prices.size()) return 0;
          int profit=0;
          if(dp[i][buy][k]!=-1) return dp[i][buy][k];
        if(!buy) {
            int buy_1=-prices[i]+check(prices,i+1,1,k,dp);
            int not_buy=check(prices,i+1,0,k,dp);
            profit=max(buy_1,not_buy);
        }
        if(buy) {
            int sell=prices[i]+check(prices,i+1,0,k+1,dp);
            int not_sell=check(prices,i+1,1,k,dp);
            profit=max(sell,not_sell);
        }

        return dp[i][buy][k]=profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        return check(prices,0,0,0,dp);
        
    }
};