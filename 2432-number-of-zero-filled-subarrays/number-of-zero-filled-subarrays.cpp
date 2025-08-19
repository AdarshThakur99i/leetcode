class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int i=0;
        int j=0;
        long long cnt=0;
        while(j<nums.size()) {
if(nums[j]==0) {
    i=j;
    while(j<nums.size() && nums[j]==0) {
   
    cnt+=(j-i+1);
   
        j++;
    }
}
j++;
        }

      
        return cnt;
    }
};

//a b c 
//abc acb bac bca cab cba