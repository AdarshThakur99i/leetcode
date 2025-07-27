class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i=0; i<nums.size(); i++) {
            int idx=nums[i];
            if(nums[i]<0) {
                idx=abs(nums[i]);
            }
            if(nums[idx-1] <0) {
                ans.push_back(idx);
            }
           else if(nums[idx-1] >0) {
                nums[idx-1]*=(-1);
            }
        }
        return ans;
    }
};