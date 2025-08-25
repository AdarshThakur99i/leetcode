class Solution {
public:
    // int check(vector<int>& nums1,vector<int>& nums2,int i) {
    //     if(i==nums1.size()) {

    //         if(nums1.back() == *max_element(nums1.begin(),nums1.end()) && nums2.back() == *max_element(nums2.begin(),nums2.end())) {
    //             return 0;
    //         }
    //         return nums1.size()+5;
    //     }

        
    //     int temp=nums1[i];
    //     nums1[i]=nums2[i];
    //     nums2[i]=temp;
    //     int swap=1+check(nums1,nums2,i+1);

    //     temp=nums1[i];
    //     nums1[i]=nums2[i];
    //     nums2[i]=temp;
    //     int skip=check(nums1,nums2,i+1);
    //     return min(swap,skip);



    // }
       
    int check(vector<int> &nums1,vector<int>& nums2,int maxi1,int maxi2) {
        bool check=true;
        int n=nums1.size();
        int cnt=0;
             for(int i=n-2; i>=0; i--) {
                 if(nums1[i]<=maxi1 && nums2[i]<=maxi2) continue;
                 else if(nums1[i]<=maxi2 && nums2[i]<=maxi1) cnt++;
                 else {
                    return INT_MAX;
                 }

            }
          
          return cnt;
    }
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
          int maxi1=nums1.back();
          int maxi2=nums2.back();
          int n=nums1.size();
        int ans=INT_MAX;
       
          int res1=(check(nums1,nums2,maxi1,maxi2));
            ans=min(ans,res1);
          
   

     res1=(check(nums1,nums2,maxi2,maxi1));
     if(res1 != INT_MAX)   ans=min(ans,res1+1);
      
     

        
   return (ans==INT_MAX) ? -1: ans;
    }
};