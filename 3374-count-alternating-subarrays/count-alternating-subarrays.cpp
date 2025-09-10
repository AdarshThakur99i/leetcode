class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int i=0;
        int j=0;
long long ans=0;
int len=1;
        while(j<nums.size()) {
           
           if(j>0 && nums[j]!=nums[j-1]) {
            len++;
            
           }
           else {
            len=1;
           }
           ans+=len;
           j++;
        
            
           
        }
        return ans;
    }
};