class Solution {
public:
         int check(vector<int>& nums,int target,int i,int currsum,vector<vector<int>>& dp) {
            if(i==nums.size()) {
                if(currsum==target) return 0;
                return INT_MIN;
            }
            if(currsum>target) return INT_MIN;
            if(dp[i][currsum]!= -1) return dp[i][currsum];
            int take=1+check(nums,target,i+1,currsum+nums[i],dp);
           int not_take=check(nums,target,i+1,currsum,dp);

           return dp[i][currsum]=max(take,not_take);
         }
     
         int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int sum=accumulate(begin(nums),end(nums),0);
        vector<vector<int>> dp(nums.size(),vector<int>(target+1,-1));
        int currsum=0;
        int res= check(nums,target,0,currsum,dp);
        return (res<0) ? -1 : res;
    }
};