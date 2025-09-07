class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int i=0;
        int j=0;
        unordered_map<int,int> mp;  
        stack<int> st;
        vector<int> nextgreat(nums.size(),-1);
        vector<int> beforegreat(nums.size(),-1);
        for(int i=nums.size()-1; i>=0; i--) {

            if(!st.empty()) {
                 while( !st.empty() && nums[i]>nums[st.top()]) {
                    if(!st.empty()) st.pop();
                 }
                 if(!st.empty()) nextgreat[i]=nums[st.top()];
                else {
                    nextgreat[i]=-1;
                }
            }
           

            st.push(i);
        }
     while(!st.empty()) st.pop();
         for(int i=0; i<nums.size(); i++) {

            if(!st.empty()) {
                 while(!st.empty() && nums[i]>nums[st.top()]) {
                    if(!st.empty()) st.pop();
                 }
                 if(!st.empty()) beforegreat[i]=nums[st.top()];
            }
           

            st.push(i);
        }
        int cnt=0;
        for(int i=0; i<nums.size(); i++) {
               if(nextgreat[i]>nums[i] && beforegreat[i]>nums[i]) cnt++;
        }
        return cnt;
    }
};