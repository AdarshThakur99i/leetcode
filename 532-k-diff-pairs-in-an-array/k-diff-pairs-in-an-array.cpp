class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]]++;
        }
       int cnt=0;
        for(int i=0; i<nums.size(); i++) {
            if(mp.count(k+nums[i])) {
                if(k!=0) {
                cnt++;}
                else {
                    if(mp[k+nums[i]]>1) {
                        cnt++;
                    }
                }
                if(mp.count(k+nums[i])) mp.erase(k+nums[i]);
               
            }
        }
        return cnt;
    }
};