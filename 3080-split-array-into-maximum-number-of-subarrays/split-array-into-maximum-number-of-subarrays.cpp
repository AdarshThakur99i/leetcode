class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
      int curr=~0;
      int cnt=0;
      for(int i=0; i<nums.size(); i++) {
        curr=curr&nums[i];

        if(curr==0) {
             curr=~0;
             cnt++;
        }
      }


       return max(cnt,1);
    }
};
