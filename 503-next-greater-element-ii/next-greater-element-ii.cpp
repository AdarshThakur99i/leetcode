class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
         vector<int> ans(nums.size(),-1);
      
         for(int i=2*nums.size()-1; i>=0; i--) {
            int idx=i%nums.size();
                while(!st.empty() && nums[st.top()] <= nums[idx]) {
                    st.pop();
                     
                }
                if(!st.empty() && nums[idx]<nums[st.top()]) {
                            ans[idx]=nums[st.top()];
                             
                }
                   st.push(idx);
        }

        return ans;
    }
};