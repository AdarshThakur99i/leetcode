class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
               long long cnt=INT_MIN;
              int temp=0;
               int n=nums.size();
               int sum=0;
int k=0;
            for(int i=0; i<nums.size(); i++) {
               temp+=(k*nums[i]);
                sum+=nums[i];
                k++;
            }
            int res=temp;
            int prev=temp;
             k=1;
              for(int i=1; i<nums.size(); i++) {
                int ne = prev + sum - n*nums[n-k];

                prev=ne;
                res=max(res,ne);
                k++;
              }
               return res;}
};