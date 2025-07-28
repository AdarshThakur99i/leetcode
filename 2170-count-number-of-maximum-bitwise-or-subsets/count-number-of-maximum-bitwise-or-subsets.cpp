class Solution {
public:
    void check(vector<int> &nums,int &maxi,int i,int &cnt,int currOrr) {
    
             if(i==nums.size()) {
                if(currOrr>maxi) {
                    maxi=currOrr;
                    cnt=1;
                }
                else if(currOrr==maxi) {
                    cnt++;
                }
                return;
             }
                  
             check(nums,maxi,i+1,cnt,currOrr | nums[i]);
             check(nums,maxi,i+1,cnt,currOrr);


    }
    int countMaxOrSubsets(vector<int>& nums) {
      int maxi=INT_MIN;
      int cnt=0;
      check(nums,maxi,0,cnt,0);
      return cnt;

    }
};