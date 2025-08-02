class Solution {
public:
   int check(vector<int> &nums,int start,int end) {
        
        if(start==end) {
return nums[end];
        }
     int take=nums[start] - check(nums,start+1,end);
     int take_last=nums[end] - check(nums,start,end-1);
       

       return max(take,take_last);
    
   }
    
    bool predictTheWinner(vector<int>& nums) {
        int total=0;
        if(nums.size()==1) return true;
      int res = check(nums,0,nums.size()-1);
      if(res>=0) return true;
        return false;
    }
};