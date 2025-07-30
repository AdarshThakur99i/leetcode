class Solution {
public:
    bool find132pattern(vector<int>& nums) {
       int maxi=INT_MIN;
       int cnt=0;
       vector<int> left_min(nums.size(),INT_MAX);
       for(int i=1; i<nums.size(); i++) {
        left_min[i]=min(left_min[i-1],nums[i-1]);
       }
        stack<int> st;
        for(int i=nums.size()-1; i>=0; i--) {
            if(nums[i]>left_min[i]) {
              
                while(!st.empty() && st.top()<=left_min[i]) {
                    st.pop();
                }
                if(!st.empty() && nums[i] > st.top()) {
                    return true;
                }
                st.push(nums[i]);
              }

        }
        return false;
    }
};