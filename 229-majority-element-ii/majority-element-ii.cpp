class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
         vector<int> temp;
         unordered_map<int,int> mp;
         unordered_set<int> st;

         for(int i=0; i<nums.size(); i++) {

            mp[nums[i]]++;
            if(mp[nums[i]]>(nums.size()/3)) {
                st.insert(nums[i]);
            }
         }
       for(auto it:st) {
        temp.push_back(it);
       }

         return temp;
    }
};