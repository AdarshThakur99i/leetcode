class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0) return 0;
        vector<int> dp(nums.size(),1);
int maxi=INT_MIN;
        for(int i=0; i<nums.size(); i++) {
            for(int j=0; j<=i-1; j++) {
                if(nums[j]<nums[i]) {
                  dp[i]=max(dp[i],dp[j]+1);
                 maxi=max(dp[i],maxi);

                }
            }
        }

        return (maxi==INT_MIN)?1:maxi;
    }
};