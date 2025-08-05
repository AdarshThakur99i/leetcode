class Solution {
public:
    int findMaxLength(vector<int>& nums) {
       
        unordered_map<int,int> mp;
      
        int ones=0;
        int zeros=0;
        int maxi=INT_MIN;
        for(int i=0; i<nums.size(); i++) {
                   if(nums[i]==1) ones++;
           if(nums[i]==0) zeros++;
           if(ones==zeros) maxi=max(maxi,i+1);
          if(mp.count((ones-zeros))) {
            maxi=max(maxi, (i-mp[(ones-zeros)]));
          }
          else {
            mp[(ones-zeros)]=i;
          }



        }
        return maxi==INT_MIN ? 0:maxi;
    }
};