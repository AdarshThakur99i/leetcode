class Solution {
public:

    int partitionArray(vector<int>& nums, int k) {
       sort(begin(nums),end(nums));
       int cnt=0;
       int i=0;
       int maxi=INT_MIN;
       int mini=INT_MAX;
       while(i<nums.size()) {
        if(max(maxi,nums[i])-min(mini,nums[i])<=k) {
            maxi=max(maxi,nums[i]);
            mini=min(mini,nums[i]);
            i++;

        }
        else {
            maxi=nums[i];
            mini=nums[i];
            cnt++;
            i++;
        }

       }
       return cnt+1;
    }
};


