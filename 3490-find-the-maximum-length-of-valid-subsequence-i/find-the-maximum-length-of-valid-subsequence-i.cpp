class Solution {
public:
    int maximumLength(vector<int>& nums) {
        if(nums.size()==2) {
            return 2;
        }
        int len=0;
        int check=false;
        for(int i=0; i<nums.size(); i++) {
            if(check==false && nums[i]%2==0) {
                check=true;
                len++;
            }
            if(check==true && nums[i]%2 !=0) {
                check=false;
                len++;
            }
        }
        check=true;
        int len2=0;
          for(int i=0; i<nums.size(); i++) {
            if(check==false && nums[i]%2==0) {
                check=true;
                len2++;
            }
            if(check==true && nums[i]%2 !=0) {
                check=false;
                len2++;
            }
        }
        int len3=0;
        int len4=0;
           for(int i=0; i<nums.size(); i++) {
            if(nums[i]%2==0) {
               len3++;
            }
            else{
                len4++;
            }
           
        }


       return max({len,len2,len3,len4});

    }
};