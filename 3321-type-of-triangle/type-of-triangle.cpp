class Solution {
public:
    bool check(vector<int> &nums) {
       if(((nums[0]+nums[1])<=nums[2]) || ((nums[0]+nums[2])<=nums[1]) || (nums[1]+nums[2])<=nums[0]) {
        return false;
       }
       return true;
    }
    string triangleType(vector<int>& nums)  { 
          if(check(nums)==false) {
            return "none";
          }
         
unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]]++;
        }

        if(mp.size()==2) {
            return "isosceles";
        }
        if(mp.size()==1) {
            return "equilateral";
        }
        if(mp.size()==3) {
            return "scalene";
        }



return "none";



    }
};