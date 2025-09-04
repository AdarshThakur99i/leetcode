class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int m=pattern.size();
        int cnt=0;
         for(int i=0; i+m<nums.size(); i++) {
                bool ok=true;
                for(int j=0; j<m; j++) {
                      if( pattern[j]==1 && !(nums[i+j+1] > nums[i+j])) ok=false;
                      if(pattern[j]==0 && !(nums[i+j+1]==nums[i+j])) ok=false;
                      if(pattern[j]==-1 && !(nums[i+j+1] < nums[i+j] )) ok=false;

                      if(!ok) break;
                }

           if(ok) cnt++;
         }
       return cnt;
    }
};

// 1 1 1 3 1 1 1 1 1 1 