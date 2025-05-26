class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
    
     long long xori=0;
     for(int i=0; i<nums.size(); i++) {
           xori=xori^nums[i];
     }

    long long mask=(xori)&(-xori);
    int groupa=0;
    int groupb=0;
     for(int i=0; i<nums.size(); i++) {
        if(nums[i]&mask) {
         groupa=groupa^nums[i];
        }
        else {
            groupb=groupb^nums[i];
        }
     }
 return {groupa,groupb};
     
    }
};