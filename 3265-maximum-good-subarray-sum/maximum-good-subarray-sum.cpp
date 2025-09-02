class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,long long> mp;
long long maxi=LLONG_MIN;
        long long pref=0;
        for(int i=0; i<nums.size(); i++) {
            int num=nums[i];
       

         if(mp.find(num)==mp.end()) {
            mp[num]=pref;
         }
         else {
            mp[num]=min((long long)mp[num],pref);
         }
          pref+=nums[i];

         if(mp.count(k+nums[i]) || mp.count(nums[i]-k)) {
            long long sum=LLONG_MIN;
            if(mp.count(k+nums[i])) sum= pref-mp[nums[i]+k];
            if(mp.count(nums[i]-k)) sum= max(sum,pref-mp[nums[i]-k]);
    maxi=max(maxi,sum);
         }
      

       }
       return maxi==LLONG_MIN?0:maxi;
  }
};