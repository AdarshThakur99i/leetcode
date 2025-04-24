class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]]++;
        }

        unordered_map<int,int> smp;

        int i=0;
         int j=0;
         int cnt=0;
         for(int i=0; i<nums.size(); i++) {
            smp.clear();
            for(int j=i; j<nums.size(); j++) {
               smp[nums[j]]++;
               if(smp.size()==mp.size()) cnt++;
               if(smp.size()>mp.size()) break;

            }
           
         }


         return cnt;
    }
};