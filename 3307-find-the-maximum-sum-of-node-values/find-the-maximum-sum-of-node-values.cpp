class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
      
long long count=0;
long long sum=0;
int mini=INT_MAX;
           for(int i=0; i<nums.size(); i++) {
                if((nums[i]^k)>nums[i]) {
                    sum+=nums[i]^k; 
                    count++; 
                }
                else {
                    sum+=nums[i];
                }

                mini=min(mini,abs(nums[i]-(nums[i]^k)));
           }
         if(count%2==0) {
            return sum;
         }
           
      
      return sum-mini;

    }
};