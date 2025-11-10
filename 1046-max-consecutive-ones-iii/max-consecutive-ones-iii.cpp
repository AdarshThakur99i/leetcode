class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int one=0;
        int maxi=0;
        int temp=k;
        while(j<nums.size()) {
            if(nums[j]==1) one++;

            else if(nums[j]==0 && temp>0) {
                one++;
                temp--;
            }
            else if(nums[j]==0 && temp==0) {
                while(temp==0 ) {
                    if(nums[i]==0) temp++;
                    i++;
                }
                temp--;


            }
           maxi=max(maxi,j-i+1);
            j++;

        }
        return maxi;
    }
};