class Solution {
public:
    int check(vector<int> prices,int i,int curr,int k,int buy,vector<vector<vector<int>>> &dp) {
         if(curr>=k || i>=prices.size()) return 0;
            if(dp[i][buy][curr]!=-1) return dp[i][buy][curr];
int profit=0;
         if(!buy) {
            int buy_1=-prices[i]+check(prices,i+1,curr,k,1,dp);
            int not_buy=check(prices,i+1,curr,k,0,dp);
            profit=max(buy_1,not_buy);
         }
         if(buy) {
            int sell=prices[i]+check(prices,i+1,curr+1,k,0,dp);
            int not_sell=check(prices,i+1,curr,k,1,dp);
            profit=max(sell,not_sell);
         }


         return dp[i][buy][curr]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));

        return check(prices,0,0,k,0,dp);
        
    }
};