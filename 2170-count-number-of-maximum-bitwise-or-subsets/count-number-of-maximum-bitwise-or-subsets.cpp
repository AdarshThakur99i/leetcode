class Solution {
public:
    int check(vector<int> &nums,int &maxi,int i,int currOrr) {
    
             if(i==nums.size()) {
                if(currOrr>maxi) {
                    maxi=currOrr;
                   return 1;
                }
                else if(currOrr==maxi) {
                 
                    return 1;
                }
                else {
                    return 0;
                }
               
             }
                  
           int take=  check(nums,maxi,i+1,currOrr | nums[i]);
           int not_take=  check(nums,maxi,i+1,currOrr);
         return take+not_take;

    }
    int countMaxOrSubsets(vector<int>& nums) {
      int maxi=INT_MIN;
      int cnt=0;
     int res= check(nums,maxi,0,0);
      return res;

    }
};