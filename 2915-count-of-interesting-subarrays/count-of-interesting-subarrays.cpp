class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
          for(int i=0; i<nums.size(); i++) {
                if(nums[i]%modulo == k) {
                    nums[i]=1;
                }
                else {
                    nums[i]=0;
                }
          } 
        int i=0;
        unordered_map<int,int> mp;
        mp[0]=1;
        long long sum=0;
        long long res=0;
        while(i<nums.size()) {
            sum+=nums[i];
            int r1=sum%modulo;
            int r2= (r1-k+modulo)%modulo;

           
res+=mp[r2];
            
            mp[r1]++;
            i++;
        }
        return res;   


    }
};