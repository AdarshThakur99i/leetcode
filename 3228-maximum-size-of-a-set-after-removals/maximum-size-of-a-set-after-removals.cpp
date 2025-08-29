class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1;
        unordered_set<int> s2;
        
int n1=nums1.size();
int n2=nums2.size();
int unique1=0;
int unique2=0;
        for(int i=0; i<nums1.size(); i++) {
            s1.insert(nums1[i]);
        }
        for(int i=0; i<nums2.size(); i++) {
            s2.insert(nums2[i]);
        }
      
        int common=0;
        for(auto it: s1) {
            if(!s2.count(it)) unique1++;
            if(s2.count(it)) common++;
        }
            for(auto it: s2) {
            if(!s1.count(it)) unique2++;
           
        }
         int mini1=min(unique1,n1/2);
         int mini2=min(unique2,n2/2);

         return min(mini1+mini2+common, n1);
        

    }
};