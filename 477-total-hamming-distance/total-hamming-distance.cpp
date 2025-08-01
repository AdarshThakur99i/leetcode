class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
         int sum=0;
         for(int i=0; i<32; i++) {
            int ones=0;
            int zeros=0;
            
         for(int j=0; j<nums.size(); j++) {
               if(((nums[j]>>i) & 1)==1) {
                ones++;
               };
               
         }
         zeros=nums.size()-ones;
         sum+=ones*zeros;
         }
         return sum;
    }
};