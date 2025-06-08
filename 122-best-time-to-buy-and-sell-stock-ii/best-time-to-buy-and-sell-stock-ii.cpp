class Solution {
public:

    int maxProfit(vector<int>& prices) {
      vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));
    dp[prices.size()][0]=dp[prices.size()][1]=0;

      for(int i=prices.size()-1; i>=0; i--) {
        for(int j=0; j<2; j++) {
int buy_1=0;
int not_buy=0;
int profit=0;

     if(!j) {
        
     buy_1=-prices[i]+dp[i+1][1];
     not_buy=dp[i+1][0];
     profit=max(buy_1,not_buy);
     }
     int sell=0;
     int not_sell=0;
     if(j) {
        
         sell= prices[i]+dp[i+1][0];
         not_sell=dp[i+1][1];
         profit=max(sell,not_sell);
     }
dp[i][j]=profit;
        }
      }
        return dp[0][0];
         


  }
};