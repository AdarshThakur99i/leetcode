class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int minIdx=0;
        int maxIdx=0;
        vector<int> ans;

        for(int j=indexDifference; j<nums.size(); j++) {
            int i=j-indexDifference;

            if(nums[i]>nums[maxIdx]) maxIdx=i;
            if(nums[i]<nums[minIdx]) minIdx=i;

            if(abs(nums[j]-nums[minIdx]) >=valueDifference) {
                ans.push_back(j);
                ans.push_back(minIdx);
                return ans;
            }
            if(abs(nums[j]-nums[maxIdx])>=valueDifference) {
                  ans.push_back(j);
                ans.push_back(maxIdx);
                return ans;
            }
        }
     
        if(ans.size()==0) return {-1,-1};
        return ans;
    }
};