class Solution {
public:
    int longestSubarray(vector<int>& nums) {
int zeck=0;
        for(int i=0; i<nums.size(); i++) {
   if(nums[i]==0) zeck++;
        }

        if(zeck==0) return max(0,(int)nums.size()-1);
        int ones=0;
        int zeros=0;
        int i=0;
        int j=0;
        int maxi=INT_MIN;
        while(j<nums.size()) {
            if(nums[j]==1) ones++;
            else zeros++;
            while(zeros>1) {
                if(nums[i]==1) ones--;
                else zeros--;
                i++;
            }
               if(zeros<=1) {
                 maxi=max(maxi,ones);
               }

            j++;

        }
        return maxi;
    }
};