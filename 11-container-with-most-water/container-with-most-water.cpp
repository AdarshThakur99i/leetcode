class Solution {
public:
    int maxArea(vector<int>& nums) {
        int i=0;
        int maxi=INT_MIN;
        int j=nums.size()-1;
        while(i<j) {
            int area=(j-i)*min(nums[i],nums[j]);
            maxi=max(maxi,area);
            if(nums[i]>nums[j]) j--;
            else {
                i++;
            }
             
            }
            return maxi;
    }
};