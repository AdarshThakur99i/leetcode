class Solution {
public:
   int check(vector<int> &nums,int start,int end) {
        if(start>end) return 0;
        if(start==end) {
return nums[end];
        }
   int take=nums[start] + min(check(nums,start+2,end),check(nums,start+1,end-1));
   int take_l= nums[end] + min(check(nums,start,end-2),check(nums,start+1,end-1));
       

       return max(take,take_l);
    
   }
    
    bool predictTheWinner(vector<int>& nums) {
        int total=accumulate(begin(nums),end(nums),0);
         
     if(nums.size()==1) return true;
      int res = check(nums,0,nums.size()-1);
      int p2=total-res;
     
        return (res>=p2);
    }
};