class Solution {
public:
    int longestSubarray(vector<int>& nums) {
      int x=*max_element(begin(nums),end(nums));            
    int i=0;
    int j=0;
    int maxi=INT_MIN;
    while(i<nums.size()) {
        if(nums[i]==x) {
            int temp=0;
            while(i<nums.size() && nums[i]==x) {
                 i++;
                 temp++;
            }
            maxi=max(maxi,temp);
            continue;
        }
        i++;
    }
    return maxi;
    }
};