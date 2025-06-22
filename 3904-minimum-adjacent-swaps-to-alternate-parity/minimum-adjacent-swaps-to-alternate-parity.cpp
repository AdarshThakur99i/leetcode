class Solution {
public:
   int helper(vector<int> nums,int state) {
     int curr=0;
     int cnt=0;
     for(int i=0; i<nums.size(); i++) {
        if(nums[i]%2==state) {
            cnt+=abs(curr-i);
            curr=curr+2;
        }

     }
     return cnt;
   }
    int minSwaps(vector<int>& nums) {
        int evenCount = 0, oddCount = 0;
        for (int num : nums) {
            if (num % 2 == 0) evenCount++;
            else oddCount++;
        }

        if (abs(evenCount - oddCount) > 1) return -1;
        int x=0;
        if(evenCount>oddCount) {
            x+=helper(nums,0);
        }
        else if(oddCount>evenCount) {
            x+=helper(nums,1);
        }
        else {
            x=min(helper(nums,0),helper(nums,1));
        }
        return x;
         
    }
};
