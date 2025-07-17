class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size()==1) return nums;
        priority_queue<int> pq;
        unordered_map<int,int> mp;
        int i=0;
        vector<int> ans;
        int j=0;
        while(i<nums.size() && j<nums.size()) {
            mp[nums[j]]++;
            pq.push(nums[j]);
        

            if( j<nums.size() && j-i+1 ==k) {
                
                while(!pq.empty()  && mp[pq.top()] <=0) {
                pq.pop();

            }
              if(!pq.empty()) {
            ans.push_back(pq.top());}
               
                 
                 mp[nums[i]]--;
            i++;
            }
           
          
           j++;
         
        }
        return ans;
    }
};