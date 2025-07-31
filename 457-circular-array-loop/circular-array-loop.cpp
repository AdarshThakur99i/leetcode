class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        
         int i=0;
         int n=nums.size();
         for(int j=0; j<nums.size(); j++) {
            i=j;
             vector<int> vis(nums.size(),0);
             bool isForward= (nums[i]>0);
         while(true) {
int prev=i;
int next=i+nums[i];
 next=((next%n)+n)%n;
           
           if(next==prev || (nums[next]>0) != isForward ) {
            break;
           }
            if(vis[i]==1) {
                return true;
            }
            vis[i]=1;
            i=next;
         }}

         return false;
    }
};