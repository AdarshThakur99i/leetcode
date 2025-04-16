class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n=nums.size();
        long long cnt=0;
        int j=0;
        int i=0;
        long long pairs=0;
        while(j<nums.size() && i<nums.size()) {
           pairs+=mp[nums[j]];
           mp[nums[j]]++;

           while(pairs>=k) {
     cnt+=n-j;
     mp[nums[i]]--;
     pairs-=mp[nums[i]];
     i++;

           }
           j++;

        }
      
           
        return cnt;
    }
};