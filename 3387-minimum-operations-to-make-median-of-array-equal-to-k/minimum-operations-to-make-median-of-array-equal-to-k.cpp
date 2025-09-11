class Solution {
public:

   long long even_check(vector<int>& nums,int k) {
             
              long long cnt=0;
            for(int i=0; i<nums.size()/2; i++) {
                     if(nums[i]<=k) {
                        continue;
                     }
                     else {
                        cnt+=(nums[i]-k);
                     }
            }
int n=nums.size();

           cnt+=abs(k-nums[n/2]);
                n=n/2+1;


        for(int i=n; i<nums.size(); i++) {
                if(nums[i]>=k) continue;
                else {
                    cnt+=(k-nums[i]);
                }
            }
            return cnt;
    }
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
          sort(begin(nums),end(nums));
          
    return even_check(nums,k);
    }
};