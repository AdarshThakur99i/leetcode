class Solution {
public:

  bool check(vector<int> &nums,int sum1,int totalSum,int i,vector<vector<int>> &dp) {
              if(sum1==(totalSum-sum1)) return true;
              if(i<0) return false;
if(dp[i][sum1]!=-1) return dp[i][sum1];
              bool take1=check(nums,sum1+nums[i],totalSum,i-1,dp);
              bool take2=check(nums,sum1,totalSum,i-1,dp);


              return dp[i][sum1]=(take1 || take2);
  }
    bool canPartition(vector<int>& nums) {
        int sum=0;
       
        for(auto it:nums) {
            sum+=it;
        } vector<vector<int>> dp(nums.size(),vector<int>(sum+1,-1));
        return check(nums,0,sum,nums.size()-1,dp);

    }
};