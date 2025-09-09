class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
          unordered_map<long long,long long> mp;
          priority_queue<pair<long long,long long>> q;
          vector<long long> ans;
          for(int i=0; i<nums.size(); i++) {
             mp[nums[i]]+=freq[i];
             if(mp[nums[i]]>0)  q.push({mp[nums[i]],nums[i]});
             while(!q.empty() && mp[q.top().second] != q.top().first) {
                    q.pop();

             }     

             if(q.empty()) {
                if(mp[nums[i]]>0) {
                    ans.push_back(mp[nums[i]]);
                     
                }
                else ans.push_back(0);

             }
             else {
                ans.push_back(q.top().first);
             }
             
            
          }

          return ans;
    }
};