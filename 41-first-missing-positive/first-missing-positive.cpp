class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool check=false;
       for(int i=0; i<nums.size(); i++) {
        if(nums[i]==1) {
            check=true;
            
        }
        if(nums[i]>nums.size() || nums[i]<=0 ) {
            nums[i]=1;
        }
        
       }
       if(check==false) return 1;

       for(int i=0; i<nums.size(); i++) {
                 
                   int x=abs(nums[i]);
                   int idx=x-1;
                  if(nums[idx]>0) nums[idx]=-nums[idx];
                   
       }
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]>0) return i+1;
        }
       return nums.size()+1;
    }
};