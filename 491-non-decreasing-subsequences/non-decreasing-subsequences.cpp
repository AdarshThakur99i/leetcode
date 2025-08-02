class Solution {
public:
vector<vector<int>> ans;
set<vector<int>> st;
    void check(vector<int> &nums,int i,vector<int>& temp,int prev) {
           if(i==nums.size()) {

            if(temp.size()>=2 && st.find(temp)==st.end()) {ans.push_back(temp);
            st.insert(temp);}
            return;
           }
        if(nums[i]>=prev) {
            temp.push_back(nums[i]);
            check(nums,i+1,temp,nums[i]);
            temp.pop_back();
        }
        check(nums,i+1,temp,prev);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        check(nums,0,temp,INT_MIN);
         return ans;
    }
};