class Solution {
public:
    int maxSum(vector<int>& nums) {
        sort(begin(nums),end(nums));
          int sum=nums[nums.size()-1];
           unordered_set<int> st;   st.insert(nums[nums.size()-1]);
      
          for(int i=nums.size()-2; i>=0; i--) {
            if(st.find(nums[i])!=st.end()) {
                continue;
            }
           sum=max(sum,sum+nums[i]);
           st.insert(nums[i]);
          }

          return sum;
    }
};