class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
         unordered_map<long long,int> mp;
         int i=0;
         int j=0;
         long long sum =0;
         long long  maxi=INT_MIN;
         while(j<nums.size()) {
            mp[nums[j]]++;
            sum+=nums[j];
            while(j-i+1 > k) {
                mp[nums[i]]--;
                sum-=nums[i];
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
                
            }
          if(mp.size() >=m && j-i+1 ==k) {
           maxi=max(maxi,sum);}
           j++;
         }
         return (maxi==INT_MIN) ? 0 : maxi;
    }
};