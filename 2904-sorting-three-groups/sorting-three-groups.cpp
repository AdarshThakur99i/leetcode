class Solution {
public:
    int minimumOperations(vector<int>& nums) {
          vector<int> temp(nums.size(),1);
          int maxi=INT_MIN;
        for(int i=0; i<nums.size(); i++) {
            for(int j=0; j<i; j++) {
              if(nums[j]<=nums[i]) {
                temp[i]=max(temp[i],temp[j]+1);
              
              }
            }  maxi=max(maxi,temp[i]);
        }
        if(maxi==INT_MIN) return 0;
        return (nums.size()-maxi);

    }
};