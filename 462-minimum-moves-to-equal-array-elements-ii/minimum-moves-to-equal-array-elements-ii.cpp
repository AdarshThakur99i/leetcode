class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int idx=-1;
        int cnt=0;
        if(nums.size()%2!=0) {
            idx=nums.size()/2;
            int val=nums[idx];
            for(int i=0; i<nums.size(); i++) {
                cnt+=abs(val-nums[i]);
            }
            
        }
        else {
            idx=nums.size()/2;
            int idx2=idx-1;
            int temp1=0;
            int temp2=0;
            for(int i=0; i<nums.size(); i++) {
                temp1+=abs(nums[idx2]-nums[i]);
                temp2+=abs(nums[idx]-nums[i]);
            }
            return min(temp1,temp2);
        }
          return cnt;
    }
};
//1 2 3 4 5 6 