class Solution {
public:
  
    int minLengthAfterRemovals(vector<int>& nums) {
      priority_queue<int,vector<int>,greater<>> minl;
      priority_queue<int,vector<int>,greater<>> minr;
int n=nums.size();
      for(int i=0; i<nums.size(); i++) {
          if(i<n/2) minl.push(nums[i]);
          else {
            minr.push(nums[i]);
          }
      }
int cnt=0;
      while(!minl.empty() && !minr.empty()) {
        if(minl.top()==minr.top()) {
            minr.pop(); cnt++;
        }
        else {
            minl.pop();
            minr.pop();
        }

      }
      return minl.size()+minr.size()+cnt;
   
    }
};

//123445

