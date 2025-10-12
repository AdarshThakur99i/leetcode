class Solution {
public:
   int check(int x,int y,vector<int>& nums1,vector<int>& nums2)  {
          
          int i=0;
          int j=0;
          int ans=INT_MAX;
          while(i<nums1.size() && j<nums2.size()) {
            if(i==x || i==y) i++;

             else {
                if(ans==INT_MAX) {
                    ans=nums2[j]-nums1[i];
                }
                else {
                    if(nums2[j]-nums1[i] != ans) {
                        return INT_MAX;
                    }
                }
                i++;
                j++;
             }
          }
          return ans;

   }
     int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(begin(nums1),end(nums1));
        sort(begin(nums2),end(nums2));
        int ans=INT_MAX;
          for(int i=0; i<nums1.size(); i++) {
            for(int j=i+1; j<nums1.size(); j++) {
                ans=min(ans,check(i,j,nums1,nums2));
            }
          }
          return ans;
    }
};