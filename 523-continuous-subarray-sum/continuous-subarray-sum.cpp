class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
       
        int total=0;
        mp[0]=-1;
        int maxi=INT_MIN;
        for(int i=0; i<nums.size(); i++) {
           
total+=nums[i];
 if(mp.count(total%k)) {
    if(i-mp[total%k]  >=2) return true;


            }
            else mp[total%k]=i;

        }
    return false;
    }
};