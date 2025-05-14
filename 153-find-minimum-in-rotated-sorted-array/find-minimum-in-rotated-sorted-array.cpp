class Solution {
public:
    int findMin(vector<int>& nums) {
       int idx=-1;
       for(int i=0; i<nums.size()-1; i++) {
        if(nums[i+1]<nums[i]) {
           return min(nums[0],nums[i+1]);
        }
       }
      
return nums[0];

    }
};