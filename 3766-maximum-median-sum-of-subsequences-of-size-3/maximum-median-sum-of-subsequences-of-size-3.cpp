class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n=nums.size();
        int steps=(n/3);
        int i=nums.size()-1;
        long long sum=0;
        while(steps>0 && i>=0) {
          
         
                sum+=nums[i-1];
                i--;
            
          
           i--;
           steps--;
        }
        return sum;
    }
};