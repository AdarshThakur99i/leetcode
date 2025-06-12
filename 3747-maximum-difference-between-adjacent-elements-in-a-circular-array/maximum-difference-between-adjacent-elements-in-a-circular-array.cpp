class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int max_diff=INT_MIN;
        int i=0;
       while(i<nums.size()) {
            if(i==nums.size()-1) {
                max_diff=max(max_diff,abs((nums[i]-nums[0])));
                break;
            } 
            else {
               max_diff=max(max_diff,abs((nums[i]-nums[i+1])));
            }
            i++; 
       }

       return max_diff;
        
    }
};