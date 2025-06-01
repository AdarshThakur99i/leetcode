class Solution {
public:
   int check(int n,int limit,int curr,vector<vector<int>> &dp) {
    if(n<0) return 0;
    if(curr>3) return 0;
    if(n==0 && curr==3) return 1;
    int take=0;
    if(dp[n][curr]!=-1) {
        return dp[n][curr];
    }
    for(int i=0; i<=limit && i<=n; i++) {
        take+=check(n-i,limit,curr+1,dp);

    }

    return dp[n][curr]=take;
   }
    long long distributeCandies(int n, int limit) {
        vector<vector<int>> dp(n+1,vector<int>(4,-1));
        return check(n,limit,0,dp);
        
    }
};