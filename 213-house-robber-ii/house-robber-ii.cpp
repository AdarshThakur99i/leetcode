class Solution {
public:

    int check(vector<int> &nums,int i,vector<int> &dp1) {

        if(i>=nums.size()-1) return 0;
if(dp1[i]!=-1) return dp1[i];
        int take= nums[i]+check(nums,i+2,dp1);
        int not_take=check(nums,i+1,dp1);
        
        return dp1[i]=max(take,not_take);
    }
    int check2(vector<int> &nums,int i,vector<int> &dp2) {

        if(i>=nums.size()) return 0;
if(dp2[i]!=-1) return dp2[i];
        int take= nums[i]+check2(nums,i+2,dp2);
        int not_take=check2(nums,i+1,dp2);

        return dp2[i]=max(take,not_take);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> dp1(nums.size(),-1);
        vector<int> dp2(nums.size(),-1);
      int ans1=check(nums,0,dp1);
      int ans2=check2(nums,1,dp2);

      return max(ans1,ans2);
    }
};