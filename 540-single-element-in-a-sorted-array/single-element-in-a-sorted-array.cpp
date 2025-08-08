class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int xoor=0;
        for(int i=0; i<nums.size(); i++) {
            xoor^=nums[i];
        }
        return xoor;
    }
};