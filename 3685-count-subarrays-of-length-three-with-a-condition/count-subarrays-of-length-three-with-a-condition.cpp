class Solution {
public:
    int countSubarrays(vector<int>& nums) {
int count=0;
        for(int i=0; i<nums.size(); i++) {
           if(i+2<nums.size()) {
            int j=i+2;
            float x=float(nums[i+1])/2;
            if(nums[j]+nums[i] == x) {
                count++;

                cout<<i<<j;


            }
           }
        }

        return count;
        
    }
};