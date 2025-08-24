class Solution {
public:
//    long long check(vector<int>& v,int i,vector<long long>& dp) {
//     if(i>=v.size()) return 0;
//     if(dp[i]!=-1) return dp[i];
//      long long a=v[i]+min({check(v,i+1,dp),check(v,i+2,dp),check(v,i+3,dp)});
  
    
//     return dp[i]=a;
//    }
     long long minIncrementOperations(vector<int>& nums, int k) {
        vector<int> v;
        for(int i=0; i<nums.size(); i++) {
            v.push_back(max(k-nums[i],0));
        }

vector<long long> dp(v.size()+3,0);
      for(int i=v.size()-1; i>=0; i--) {
        dp[i]=v[i]+min({dp[i+1],dp[i+2],dp[i+3]});
      }
          return (min({dp[0],dp[1],dp[2]}));
    }
};