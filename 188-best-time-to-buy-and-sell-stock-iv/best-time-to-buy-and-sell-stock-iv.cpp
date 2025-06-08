class Solution {
public:

    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(2,vector<int>(k+1,0)));

      for(int i=prices.size()-1; i>=0; i--) {
        for(int j=0; j<2; j++) {
            for(int t=0; t<k; t++) {
                int profit=0;
         if(!j) {
            int buy_1=-prices[i]+dp[i+1][1][t];
            int not_buy=dp[i+1][0][t];
            profit=max(buy_1,not_buy);
         }
         if(j) {
            int sell=prices[i]+dp[i+1][0][t+1];
            int not_sell=dp[i+1][1][t];
            profit=max(sell,not_sell);
         }
        dp[i][j][t]=profit;
            }
        }
      }

        return dp[0][0][0];
        
    }
};