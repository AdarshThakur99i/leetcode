class Solution {
public:
    int minMoves(vector<int>& nums) {
       int mini=*min_element(begin(nums),end(nums));
       long long sum=0;
       int n=nums.size();
       for(int i=0; i<nums.size(); i++) {
sum+=nums[i];
       }  
            int m=sum -(mini*n);
     return m;
    }
};
//1 3 5 9