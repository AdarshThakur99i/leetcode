class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int idx=0;
        vector<int> newarr;
        bool ist=false;
           for(int i=0; i<nums.size()-1; i++) {
           if(nums[i]>nums[i+1]) {idx=i+1; break; }
           }

           int l=idx;
           int r=nums.size()-1;

           while(l<=r) {
            int mid=l+(r-l)/2;

            if(nums[mid]==target) return true;

            else if(nums[mid]>target)  r=mid-1;

            else {
                l=mid+1;
            }
           }


           l=0;
           r=idx-1;
            while(l<=r) {
            int mid=l+(r-l)/2;

            if(nums[mid]==target) return true;

            else if(nums[mid]>target)  r=mid-1;

            else {
                l=mid+1;
            }
           }



           return false;
           
    }
};