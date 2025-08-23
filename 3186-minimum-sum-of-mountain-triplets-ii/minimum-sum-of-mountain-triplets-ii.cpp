class Solution {
public:
    int minimumSum(vector<int>& nums) {
        vector<int> minLeft(nums.size(),INT_MAX);
        for(int i=0; i<nums.size(); i++) {
            if(i==0) minLeft[i]=nums[i];
            else minLeft[i]=min(minLeft[i-1],nums[i]);
        }
    vector<int> minRight(nums.size(),INT_MAX);
    for(int i=nums.size()-1; i>=0; i--) {
          if(i==(nums.size()-1)) minRight[i]=nums[i];
          else minRight[i]=min(minRight[i+1],nums[i]);
    }
        int mini=INT_MAX;
        for(int i=nums.size()-1; i>=0; i--) {
             if(nums[i]>minLeft[i] && nums[i]>minRight[i]) {
                   
                
                  
                    mini=min(mini,(minLeft[i]+nums[i]+minRight[i]));
                   

             }
             
        }
        return (mini==INT_MAX)?-1:mini;
    }
};