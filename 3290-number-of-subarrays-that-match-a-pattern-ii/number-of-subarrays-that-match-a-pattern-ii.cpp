class Solution {
public:
    void build(vector<int> &temp,vector<int>& lsp) {
        lsp[0]=0;
        int len=0;
        int i=1;
        while(i<temp.size()) {
               if(temp[i]==temp[len]) {
               len++;   lsp[i]=len;   
                i++;
               }
               else {
                   if(len>0) {
                    len=  lsp[len-1];
                   }
                   else {
                    lsp[i]=0;
                    i++;
                   }
               }
        }
    }
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
         vector<int> temp;
         for(int i=1; i<nums.size(); i++) {
            if(nums[i]>nums[i-1]) temp.push_back(1);
            else if(nums[i]==nums[i-1]) temp.push_back(0);
            else {
                temp.push_back(-1);
            }
         }
         vector<int> lsp(pattern.size(),0);
         build(pattern,lsp);
          
          int i=0;
          int j=0;
          int cnt=0;
          while(i<temp.size()) {
            if(temp[i]==pattern[j]){
                  i++;
                  j++;
                  if(j==pattern.size()) {
                    cnt++;
                    j=lsp[j-1];
                  }


            }
            else {
                if(j>0) {
                    j=lsp[j-1];
                }
                else  i++;
               
            }
          }
          return cnt;  
          
    } 
};