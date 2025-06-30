class Solution {
public:
 
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
      
        if(nums.size()<=1) return nums;
        sort(begin(nums),end(nums));
         vector<int> temp(nums.size(),1);
         vector<int> prev(nums.size(),-1);
         int idx=-1;
         int maxi=INT_MIN;
      for(int i=0; i<nums.size(); i++) {
        for(int j=0; j<i; j++) {
            
                 if((nums[j]%nums[i]==0) || (nums[i]%nums[j]==0)) {
                    if(temp[j]+1 > temp[i]) {
                    temp[i]=max(temp[i],temp[j]+1);
                    prev[i]=j;
                  
                    }
                 
            }
        }
         if(temp[i]>maxi) {
                    maxi=temp[i];
                    idx=i;
                   }
      }
      vector<int> ans;
      while(idx!=-1) {
       ans.push_back(nums[idx]);
       idx=prev[idx];
      }

    reverse(begin(ans),end(ans));
    return ans;
    }
};
