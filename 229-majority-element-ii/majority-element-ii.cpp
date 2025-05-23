class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1=0;
        int maj1=0;
        int count2=0;
        int maj2=0;
        for(int i=0; i<nums.size(); i++) {
             if(nums[i]==maj1) {
                count1++;
             }
             else if(nums[i]==maj2) {
                count2++;
             }

             else if(count1==0) {
                count1=1;
                maj1=nums[i];
        }
          else if(count2==0) {
            count2=1;
            maj2=nums[i];
          }
          else {
            count1--;
            count2--;
          }

        }
        int freq1=0;
        int freq2=0;
        vector<int> temp;
        for(int i=0; i<nums.size(); i++) {
          if(nums[i]==maj1) {
            freq1++;
            
          }
          if(nums[i]==maj2) {
            freq2++;
          }

        }
        if(freq1>floor(nums.size()/3)) temp.push_back(maj1);
        if(maj1!=maj2) {
        if(freq2>floor(nums.size()/3)) temp.push_back(maj2);}

        return temp;


    }
};