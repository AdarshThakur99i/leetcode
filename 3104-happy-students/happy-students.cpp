class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int ans=0;
        if(nums[0]>0) ans++;
         for(int i=1; i<nums.size(); i++) {
         if((nums[i-1] < i) && (nums[i]>i)) {
            ans+=1;
         }
         }
         if(nums[nums.size()-1] < nums.size()) ans++;
         return ans;
    }
};