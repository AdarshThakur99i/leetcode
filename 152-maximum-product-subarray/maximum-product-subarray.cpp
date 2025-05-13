class Solution {
public:
    int maxProduct(vector<int>& nums) {
     
       int maxi=INT_MIN;
       long long prefix=1;
       long long suffix=1;
       long long ans=INT_MIN;
       for(int i=0; i<nums.size(); i++) {

        if(prefix==0) {
            prefix=1;
        }
        if(suffix==0) {
            suffix=1;
        }
            prefix=prefix*nums[i];
            suffix=suffix*nums[nums.size()-i-1];

            ans=max(ans,max(prefix,suffix));
      
      
       }
        return ans;
    }
};