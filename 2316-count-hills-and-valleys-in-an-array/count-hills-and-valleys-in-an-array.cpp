class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int cnt=0;
        int prev=INT_MIN;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==prev) continue;
            bool leftHill=false;
            bool rightHill=false;
            bool leftVally=false;
            bool rightVally=false;
            for(int j=i-1; j>=0; j--) {
                if(nums[j]<nums[i]) {
                    leftHill=true;
                    break;
                }
                else if(nums[j]>nums[i]) {
                    leftVally=true;
                    break;
                }
            }
            for(int j=i+1; j<nums.size(); j++) {
                if(nums[i]!=nums[j]) {
                if(nums[j] > nums[i] && leftVally) {
                    cnt++;
                    
                }
                else if(nums[j] < nums[i] && leftHill) {
                    cnt++;
                    
                }
                break;
            }
            }
            prev=nums[i];
        }
        return cnt;
    }
};