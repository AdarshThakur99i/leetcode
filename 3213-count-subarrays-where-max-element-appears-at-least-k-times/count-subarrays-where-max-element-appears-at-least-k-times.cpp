class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        int i=0;
        int maxi=*max_element(begin(nums),end(nums));
        long long count=0;
        int n=nums.size();
        int counthree=0;
        int j=0;
        while(j<nums.size())  {
     if(nums[j]==maxi) {
        counthree++;
     }
   

      while(counthree>=k) {
        if(nums[i]==maxi) {
            counthree--;
        }
        i++;
        count+=n-j;
        
      }
      
   j++;


        


        }

        return count;
    }
};