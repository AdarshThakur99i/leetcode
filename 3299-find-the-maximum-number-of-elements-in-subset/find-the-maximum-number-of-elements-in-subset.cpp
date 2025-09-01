class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,long long> mp;
        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]]++;
        }
        long long maxi=(mp.count(1))?((mp[1]%2 !=0)? mp[1] : mp[1]-1): 1;
           sort(begin(nums),end(nums));
           for(int i=0; i<nums.size(); i++) {
            // if(nums[i]==1) {
            //     maxi=max(maxi,1);
            //     continue;
            // }
           
                
                    long long cnt=0;
                    long long val=nums[i];
                      
                    while(val<=1e9 && mp.count(val) && mp[val]>=2 && val !=1) {
                        cnt+=2;
                        val*=val;
                    }
                     if(mp.count(val)) cnt++;
                     else cnt--;
                 
                   
                   maxi=max(maxi,cnt);
           }
           
           return maxi;
    }
};