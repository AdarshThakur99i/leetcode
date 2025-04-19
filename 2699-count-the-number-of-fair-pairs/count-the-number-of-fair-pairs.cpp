class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
       
         
            long long count=0;
            sort(begin(nums),end(nums));
       
       for(int i=0; i<nums.size(); i++) {
           
           int left=lower-nums[i];
           int right=upper-nums[i];


           int l=lower_bound(begin(nums)+i+1,end(nums),left)-nums.begin();
           int r=upper_bound(begin(nums)+i+1,end(nums),right)-nums.begin();

           count+=(r-l);


       }

            
        
            return count;
    }
};