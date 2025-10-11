class Solution {
public:
const int MOD=1e9+7;
    int check(int one,int zero,bool curr,int limit,vector<vector<vector<int>>>& dp) {
        if(one==0 && zero==0) return 1;
        if(dp[one][zero][curr]!=-1) return dp[one][zero][curr];
         int ans=0;
        if(curr==0) {
            for(int i=1; i<=min(one,limit); i++) {
                ans=(ans+check(one-i,zero,1,limit,dp)%MOD)%MOD;
            }
        }
        if(curr==1) {
            for(int i=1; i<=min(zero,limit); i++) {
                ans=(ans+check(one,zero-i,0,limit,dp)%MOD)%MOD;
            }
        }

        return dp[one][zero][curr]=ans%MOD;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        int sz=0;
        vector<vector<vector<int>>> dp(one+1,vector<vector<int>>(zero+1,vector<int>(2,-1)));
        int a=check(one,zero,0,limit,dp)%MOD;
        int b=check(one,zero,1,limit,dp)%MOD;
        return (a+b)%MOD;

    }
};