class Solution {
public:
    int check(vector<int> &nums,int i,int target,int sum,vector<vector<int>> &dp,int offset) {
        
         if(i<0) {
            if(sum==target) return 1;
            else return 0;
         }
         if(dp[i][sum+offset]!=-1) return dp[i][sum+offset];


         int neg=check(nums,i-1,target,sum+(-nums[i]),dp,offset);

         int pos=check(nums,i-1,target,sum+nums[i],dp,offset);

         return dp[i][sum+offset]=neg+pos;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(auto it: nums) {
            sum+=abs(it);
        }
        int offset=sum;

        vector<vector<int>> dp(nums.size(),vector<int>(2*sum+1,-1));
         return check(nums,nums.size()-1,target,0,dp,offset);
    }
}; 