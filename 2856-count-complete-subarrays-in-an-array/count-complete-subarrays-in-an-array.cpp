class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> mp;
        for(int i=0; i<nums.size(); i++) {
           mp.insert(nums[i]);
        }

        unordered_map<int,int> smp;

        int i=0;
         int j=0;
         int cnt=0;
         while(j<nums.size()) {
         smp[nums[j]]++;
            while(smp.size()==mp.size()) {
               cnt+=nums.size()-j;
              smp[nums[i]]--;
                if(smp[nums[i]]==0) smp.erase(nums[i]);
            i++;
            }
           
            j++;

         }

      

         return cnt;
    }
};