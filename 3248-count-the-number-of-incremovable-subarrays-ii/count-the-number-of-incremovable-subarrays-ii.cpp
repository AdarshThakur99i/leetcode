class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
         int i=0;
         while(i+1<nums.size() && nums[i+1]>nums[i]) {

            i++;
         }
         long long pref=i;
          long long j=nums.size()-1;
          while((j-1) >=0 && nums[j-1]<nums[j]) {
            j--;
          }
          long long suff=j;

          if(pref==(n-1)) {
            return ((long long)n*((long long)n+1))/2;

          }
ans+=(pref+1);
ans+=(n-suff);
int r=suff;
          for(int l=0; l<=pref; l++) {

            while(r<n && nums[l]>=nums[r]) {
                r++;
            }
            ans+=(n-r);
          }
ans++;
          return ans;
          
    }
}; 