class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size()<3) return 0;
        sort(begin(nums),end(nums));
        int cnt=0;
        for(int i=0; i<nums.size()-2; i++) {
            if(nums[i]==0) continue;
            for(int j=i+1; j<nums.size()-1; j++) {
                  if(nums[j]==0) continue;
                int val=nums[i]+nums[j];
                auto idx=lower_bound(nums.begin()+j+1,nums.end(),val);
             cnt+=idx -(nums.begin()+j+1);
            }
        }
        return cnt;
    }
};