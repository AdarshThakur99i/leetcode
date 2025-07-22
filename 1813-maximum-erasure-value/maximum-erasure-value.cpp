class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int currsum=0;
        unordered_map<int,int> mp;

int i=0;
int j=0;
int maxi=INT_MIN;
 
while(j<nums.size()) {
     while(i<nums.size() && mp[nums[j]]>=1) {
    
      currsum-=nums[i];
      mp[nums[i]]--;
      i++;
       
     
     }
    
        mp[nums[j]]++;
        currsum+=nums[j];
        j++;
          maxi=max(maxi,currsum);
}
return maxi;
    }
};