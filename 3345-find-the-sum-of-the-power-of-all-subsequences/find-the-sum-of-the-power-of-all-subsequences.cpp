class Solution {
public:
int K;
const int MOD=1e9+7;
   int modPow(int base,int exp) {
    if(exp==0) return 1;

        long long half=modPow(base,exp/2);
        long long res=(half*half)%MOD;

        if(exp%2 !=0) {
            res=(res*base)%MOD;
        }

        return res%MOD;
   }
    int check(vector<int>& nums,int i,int sum ,int len,vector<vector<vector<int>>> &dp){
        if(sum>K) return 0;
            if(i==nums.size()) {

                if(sum==K) return modPow(2,(nums.size()-len));   
                return 0;
            }
            if(dp[i][sum][len]!=-1) return dp[i][sum][len];
            int take=check(nums,i+1,sum+nums[i],len+1,dp);
            int not_take=check(nums,i+1,sum,len,dp);

            return dp[i][sum][len]=(take+not_take)%MOD;
    }
    int sumOfPower(vector<int>& nums, int k) {
        K=k;
      vector<vector<vector<int>>> dp(nums.size(),vector<vector<int>>(K+5,vector<int>(nums.size(),-1)));
          return check(nums,0,0,0,dp)%MOD;
    }
};