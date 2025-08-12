class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> minRight(nums.size(),INT_MAX);
        minRight[nums.size()-1]=nums.back();
        for(int i=nums.size()-2; i>=0; i--) {
               minRight[i]=min(nums[i],minRight[i+1]);
        }
        vector<int> maxLeft(nums.size(),0);
        maxLeft[0]=nums[0];
      for(int i=1; i<nums.size(); i++) {
maxLeft[i]=max(maxLeft[i-1],nums[i]);
      }
      int i=0;
      int j=nums.size()-1;
      while(i<nums.size() && minRight[i]==nums[i]) {
        i++;
      }
         while(j>=0 && maxLeft[j]==nums[j]) {
            j--;
         }
         if(j<0 || i>=nums.size()) return 0;
         return (j-i+1);
    }
};