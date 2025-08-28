class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(begin(nums),end(nums));
    long long sum=accumulate(begin(nums),end(nums),0LL);
          int idx=-1;
           for(int i=nums.size()-1; i>=0; i--) {
       
               sum-=nums[i];
               if(sum>nums[i]) {
                idx=i;
                break;
               }
   
           }
           if(idx==-1) return -1;
           sum=0;
           for(int i=0; i<=idx; i++) {
              sum+=nums[i];
           }

           return sum;
    }
};

//1 2 2 6 9 10 