class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
         vector<int> temp=nums;
         sort(begin(temp),end(temp));
         int i=0;
         int j=temp.size()-1;

         while(i<temp.size() && temp[i]==nums[i]) {
            i++;
         }
         while(j>i && temp[j]==nums[j]) {
            j--;
         }
         if(j==i) return 0;

         return (j-i+1);
         
    }
};