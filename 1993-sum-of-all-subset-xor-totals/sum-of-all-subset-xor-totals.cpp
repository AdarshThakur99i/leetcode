class Solution {
public:
      int solve(vector<int> &nums,int i,int currXor) {

        if(i<0) {
            return currXor;
        }
   
        int take=solve(nums,i-1,currXor^nums[i]);
        int not_take=solve(nums,i-1,currXor);

       return take+not_take;
      }
    int subsetXORSum(vector<int>& nums) {
        int xorr=0;

       
        return  solve(nums,nums.size()-1,xorr);
    }
};