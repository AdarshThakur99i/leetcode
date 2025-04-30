class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count_even=0;

        for(int i=0; i<nums.size(); i++) {

            int temp=nums[i];
            int cnt=0;
            while(temp>0) {
                cnt++;
                temp=temp/10;
            }

            if(cnt%2==0) count_even++;
        }

        return count_even;
        
    }
};