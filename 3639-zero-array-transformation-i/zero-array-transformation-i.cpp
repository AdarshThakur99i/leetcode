class Solution {
public:
    
    bool differ(vector<int> &nums,vector<vector<int>>& queries) {
          
     vector<int> diff(nums.size(),0);
     for(int i=0; i<queries.size(); i++) {
        int l=queries[i][0];
        int r=queries[i][1];

        diff[l] -=1;
        if(r+1<nums.size()) {
            diff[r+1] +=1;
        }

     }

     for(int i=1; i<diff.size(); i++) {
        diff[i]+=diff[i-1];
     }
      
      for(int i=0; i<nums.size(); i++) {
        if((nums[i]+diff[i])<=0) continue;
        nums[i]+=diff[i];
        if(nums[i]!=0) return false;
      }

      return true;

    }
 
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {

        return differ(nums,queries);
         
    }
};