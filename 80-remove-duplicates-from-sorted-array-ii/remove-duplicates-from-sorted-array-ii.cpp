class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]]++;

            if(mp[nums[i]]>2) {
               mp[nums[i]]--; 
                 nums.erase(nums.begin()+i);
                 i--;
              
            }
           
        }
        return nums.size();
    }
};