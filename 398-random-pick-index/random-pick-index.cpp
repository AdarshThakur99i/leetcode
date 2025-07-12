class Solution {
public:
vector<int> ans;   unordered_map<int,vector<int>> mp;
    Solution(vector<int>& nums) {
        ans=nums;
         
      for(int i=0; i<ans.size(); i++) {
     
              mp[nums[i]].push_back(i);
        
      }
    }
    
    int pick(int target) {
        int sz = mp[target].size();
        int idx = rand() % sz;
        return mp[target][idx];
       
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */