class Solution {
public:

   int check(vector<vector<int>>& offers,int i,vector<int>& start,vector<int> &dp) {
     
        if(i==offers.size()) {
              return 0;
        }
        if(dp[i] !=-1) {
            return dp[i];
        }
        int not_take=check(offers,i+1,start,dp);
         int take=0;
      
      int idx=upper_bound(begin(start),end(start),offers[i][1])-begin(start);
    take=offers[i][2]+check(offers,idx,start,dp);

        return dp[i]=max(take,not_take);
    
   }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(begin(offers),end(offers),[](const vector<int>& a,const vector<int>& b) {
              return a[0]<b[0];
        });
         
   vector<int> start;
   for(int i=0; i<offers.size(); i++) {
    start.push_back(offers[i][0]);
   }
   vector<int> dp(offers.size(),-1);
    
      return check(offers,0,start,dp);
    }
};