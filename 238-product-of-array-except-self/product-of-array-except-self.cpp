class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       vector<int> prefix(nums.size(),1);
       vector<int> suffix(nums.size(),1);
        prefix[0]=1;
        suffix[nums.size()-1]=1;
        for(int i=1; i<nums.size(); i++) {
            prefix[i]=1;
            prefix[i]=prefix[i-1]*nums[i-1];
            suffix[nums.size()-1-i]=1;
            suffix[nums.size()-i-1]=suffix[nums.size()-i]*nums[nums.size()-i];

            
        }
        for(int i=0; i<nums.size(); i++) {
            nums[i]=prefix[i]*suffix[i];
        }

        return nums;
    }
};