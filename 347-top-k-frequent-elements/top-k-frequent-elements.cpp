class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> temp;
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>> st;
      for(auto it: mp) {
          st.push({it.second,it.first});
      }
      while(!st.empty() && k>0) {
        auto x=st.top();
        st.pop();
        temp.push_back(x.second);

        k--;
      }
      return temp;
    }
};