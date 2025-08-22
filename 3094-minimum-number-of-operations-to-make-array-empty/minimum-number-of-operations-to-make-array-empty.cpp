class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]]++;
        }
        int cnt=0;
        for(auto &it: mp) {
            if(it.second%3 ==0) {
                cnt+=it.second/3;
                it.second=0;
            }
            else if(it.second>3 && (it.second%3)==1) {
                  cnt+=it.second/3 -1;
                it.second=it.second%3 +3;
              
            }
            else if(it.second>3 && (it.second%3) ==2) {
                      cnt+=it.second/3;
                      it.second=it.second%3;
            }
             
          if(it.second>=2) {
              cnt+=it.second/2;
              it.second=it.second%2;
          }
            
        }
        for(auto it: mp) {
            if(it.second >0) return -1;
        }
        return cnt;
        
    }
};