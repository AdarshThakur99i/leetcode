class Solution {
public:
    int check(vector<int> &nums,int i,int target,int sum) {
         if(i<0) {
            if(sum==target) return 1;
            else return 0;
         }


         int neg=check(nums,i-1,target,sum+(-nums[i]));

         int pos=check(nums,i-1,target,sum+nums[i]);

         return neg+pos;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
         return check(nums,nums.size()-1,target,0);
    }
};