class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xore=0;
        int cnt=0;
        for(int i=0; i<32; i++) {
            int kthbit=(k>>i)&1;
            int one=0;
            int zero=0;
        for(int j=0; j<nums.size(); j++) {
            int currbit=(nums[j] >>i)&1;
            if( currbit==1) {
                one++;
            }
            if(currbit==0) zero++;
        }
          if(kthbit==1) {
            if(one%2 ==0) cnt++;
          }
          else if(kthbit==0) {
            if(one%2 !=0) cnt++;
          }
        }
        return cnt;
    }
};

// 0 0 0
// 1 0 1
// 0 1 1
//1 1 0