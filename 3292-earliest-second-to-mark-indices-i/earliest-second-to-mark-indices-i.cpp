class Solution {
public:
 bool check(vector<int>& nums, vector<int>& changeIndices,int t) {
int time=0;
        vector<int> last_pos(nums.size()+1,-1);
        for(int i=0; i<=t; i++) {
            int idx=changeIndices[i];
            last_pos[idx]=i+1;
        }
        for(int i=1; i<last_pos.size(); i++) {
            if(last_pos[i]==-1) {
                return false;
            }
        }
      map<int,int> mp;
      for(int i=1; i<last_pos.size(); i++) {
           mp[last_pos[i]]=i;
      }
      int time_passed=0;
      for(auto it: mp) {
        int idx=it.second;
        int pos=it.first;
        int required_time=nums[idx-1]+1;
        if(required_time + time_passed > pos) {
            return  false; 
        }
           time_passed+=required_time;
      }



return true;


  
 }
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        // sort(begin(changeIndices),end(changeIndices));
        int m=changeIndices.size();
         int time=0;
         int l=0;
         int r=m-1;
         int ans=-1;
       while(l<=r) {
        int mid=l+(r-l)/2;
             if(check(nums,changeIndices,mid)) {
                ans=mid;
                r=mid-1;
             }
             else {
                l=mid+1;
             }
       }
  return ans==-1 ? -1:ans+1;
    }
};