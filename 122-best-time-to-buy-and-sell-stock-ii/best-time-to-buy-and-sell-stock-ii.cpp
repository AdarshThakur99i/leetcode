class Solution {
public:

    int check(vector<int> &prices,int i,int buy,vector<vector<int>> &dp) {
        
        if(i>=prices.size()) return 0;

        if(dp[i][buy]!=-1) return dp[i][buy];
int buy_1=0;
int not_buy=0;
int profit=0;

     if(!buy) {
        
     buy_1=-prices[i]+check(prices,i+1,1,dp);
     not_buy=check(prices,i+1,0,dp);
     profit=max(buy_1,not_buy);
     }
     int sell=0;
     int not_sell=0;
     if(buy) {
        
         sell= prices[i]+check(prices,i+1,0,dp);
         not_sell=check(prices,i+1,1,dp);
         profit=max(sell,not_sell);
     }

     return dp[i][buy]=profit;
     

    } 
    int maxProfit(vector<int>& prices) {
      vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return check(prices,0,0,dp);
         


  }
};