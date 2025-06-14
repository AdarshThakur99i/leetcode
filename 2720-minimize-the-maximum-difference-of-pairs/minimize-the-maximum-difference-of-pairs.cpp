class Solution {
public:
    int check(int mid,vector<int> nums,int p) {
             int count=0;
             for(int i=0; i<nums.size(); i++) {
                  if(i+1<nums.size() && (nums[i+1]-nums[i])<=mid) {
                          count++;
                          i++;
                  }
             }
             
             return count;

    }
   
    int minimizeMax(vector<int>& nums, int p) {
           sort(begin(nums),end(nums));
           int l=0;
           int result=0;
           int r=nums[nums.size()-1]-nums[0];
           while(l<=r) {
            int mid=l+(r-l)/2;
      if(check(mid,nums,p)>=p) {
           result=mid;
           r=mid-1;
      }
      else {
        l=mid+1;
      }
           }  

           return result;
    }
};