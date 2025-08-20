class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
if(nums.size()==0) return {};
if(k==1) return nums;

          unordered_map<int,int> mp;
          priority_queue<int> q;
          vector<int> temp;
          int i=0;
          int j=0;
          while(j<nums.size()) {
            mp[nums[j]]++;
            q.push(nums[j]);
            while(j-i+1 >k) {
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
               
             i++;
                
            } 
             
                    while(!q.empty() && !mp.count(q.top())) {
                        q.pop();
                    }
                  
                
            if(j-i+1 ==k && !q.empty()) temp.push_back(q.top());
            j++;
          }

       return temp;
    }
};