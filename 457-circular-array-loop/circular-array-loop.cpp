class Solution {
public:
   int getIdx(int i,vector<int> &nums) {
    int n=nums.size();
    return (((i+nums[i])%n)+n)%n;
   }
    bool circularArrayLoop(vector<int>& nums) {
          int i=0;
          int n=nums.size();
          for(int i=0; i<nums.size(); i++) {
            if(nums[i]==0) continue;
             bool isForward=(nums[i]>0);
int slow=i;
int fast=i;
            while(true) {
                slow=getIdx(slow,nums);
               fast=getIdx(fast,nums);
               if((nums[fast]>0) != isForward || nums[fast]==0) {
                break;
               }
               fast=getIdx(fast,nums);
 if((nums[fast]>0) != isForward || nums[fast]==0) {
                break;
               }
               if(slow==fast){
                if(getIdx(slow,nums)==slow) break;
                return true;
               }
               if((nums[slow]>0) != isForward || nums[slow]==0) break;
            }

            int index=i;
            while((nums[index]>0)==isForward && nums[index]!=0) {
                int newid=getIdx(index,nums);
                nums[index]=0;
                index=newid;
            }
          }
          return false;
    }
};