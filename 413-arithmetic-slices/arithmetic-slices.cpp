class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int cnt=0;
         for(int i=0; i<nums.size(); i++) {
            int diff=INT_MAX;
            for(int j=i+1; j<nums.size(); j++) {
                 if(diff==INT_MAX) {
                    diff=nums[j]-nums[i];
                 }
                 else if(j-i+1 >=3) {
                    if(nums[j]-nums[j-1] != diff) {
                        break;
                    }
                    else {
                        cnt++;
                    }
                 }
            }
         }
         return cnt;
    }
};