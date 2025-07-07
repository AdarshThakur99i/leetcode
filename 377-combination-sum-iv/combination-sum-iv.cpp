class Solution {
public:
    int check(vector<int> &nums,int target,vector<int> &dp) {
       
    if(target==0) return 1;
    if(target<0) return 0;
    if(dp[target]!=-1) return dp[target];
        int ways=0;
     for(int j=0; j<nums.size(); j++) {
           ways+=check(nums,target-nums[j],dp);
     }

    return dp[target]=ways;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int cnt=0;
       vector<int> dp(target+1,-1);
        return check(nums,target,dp);
        
    }
};