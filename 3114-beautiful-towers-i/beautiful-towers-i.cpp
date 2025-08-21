class Solution {
public:
    long long sumCheck(vector<int> nums,long long idx) {
                
                int i=idx;
                long long mini=LLONG_MAX;
                while(i>=0) {
          mini=min(mini,(long long)nums[i]);       
             if(nums[i]>mini) {
                         nums[i]=mini;
                    }

i--;
                }
                i=idx;
              mini=LLONG_MAX;
                while(i<nums.size()) {
               mini=min(mini,(long long)nums[i]);  
                   if(nums[i] > mini) {
                    nums[i]=mini;
                  }
               
                  i++;
                }
        long long sum=accumulate(nums.begin(),nums.end(),0LL);

        return sum;
                

    }
    long long maximumSumOfHeights(vector<int>& heights) {
        long long maxi=LLONG_MIN;
       
            
           
          

             for(int i=0; i<heights.size(); i++) {
                long long res=sumCheck(heights,i);
               maxi=max(maxi,res);
             }

               return maxi;
    }
};