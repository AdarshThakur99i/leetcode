class Solution {
public:
    void sortColors(vector<int>& nums) {
       int count_0=0;
       int count_1=0;
       int count_2=0;

       for(int i=0; i<nums.size(); i++) {
        if(nums[i]==0) count_0++;

        else if(nums[i]==1) count_1++;
        else {
            count_2++;
        }
       }

       for(int i=0; i<nums.size(); i++) {

        if(count_0>0) {
            nums[i]=0;
            count_0--;
            continue;
        }

      if(count_1>0){
            nums[i]=1;
            count_1--;
            continue;
        }

        if(count_2>0) { 
            nums[i]=2;
            count_2--;
            continue;
        }
       }

      
    }
};