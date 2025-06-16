class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxi=INT_MIN;
        int mini=nums[0];
         for(int i=0; i<nums.size(); i++) {
                 if(nums[i]>mini) {
                    maxi=max(nums[i]-mini,maxi);
                 }
                 else {
                    mini=nums[i];
                 }
          }
        

        return (maxi==INT_MIN)?-1:maxi;
    }
};