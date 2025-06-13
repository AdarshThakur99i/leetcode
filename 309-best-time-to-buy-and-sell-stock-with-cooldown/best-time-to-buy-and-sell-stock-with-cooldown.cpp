class Solution {
public:
    int check(vector<int> prices,int i,int buyed,vector<vector<int>> &dp) {
         if(i>=prices.size()) {
            return 0;

         }
         if(dp[i][buyed]!=-1) return dp[i][buyed];
         int buy=0;
     if(!buyed) {
         buy=-prices[i]+check(prices,i+1,1,dp);}
    int sell=0;    if(buyed) {
         sell=prices[i]+check(prices,i+2,0,dp); }
        int not_did =check(prices,i+1,buyed,dp);

        return dp[i][buyed]=max({buy,sell,not_did});
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return check(prices,0,0,dp);
        
    }
};