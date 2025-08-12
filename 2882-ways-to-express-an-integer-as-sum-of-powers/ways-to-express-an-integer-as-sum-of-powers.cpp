class Solution {
public:
const long long MOD=1e9+7;


int cPow(long long base,long long exp) {
    if(exp==0) return 1;
          int half=cPow(base,exp/2);
          int res=half*half;

          if(exp%2==1) res=res*base;

          return res;
         

}
    int check(int n,long long x,long long i,vector<vector<int>>& dp) {
        
        if(n==0) {
            return 1;
        }
        if(dp[n][i]!=-1) return dp[n][i];
       
        long long res=0;
        for(long long j=i+1; j<=n; j++) {
            long long power=static_cast<long long>(cPow(j,x));
            if(power>n) break;
              res= (res+(check((n-power),x,j,dp)));
        }

        return dp[n][i]=res%MOD;
    }
    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return check(n,x,0,dp);
    }
};