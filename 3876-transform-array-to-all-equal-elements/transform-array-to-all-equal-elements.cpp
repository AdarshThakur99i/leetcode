class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        vector<int> temp=nums;
    int count=0;
    for(int i=0; i<nums.size(); i++) {
        if(i+1 < nums.size() && nums[i]==-1) {
            count++;
           nums[i]*=(-1);
     
            nums[i+1]*=-1;
           
        }
        
    }
    if(count<=k) {
        int i=0;
        for( i=0; i<nums.size(); i++) {
            if(nums[i]==1) continue;
            else {
                break;
            }
        }
        if(i==nums.size()) return true;

    }
    count=0;

   for(int i=0; i<temp.size(); i++) {
        if(i+1 <temp.size() && temp[i]==1) {
            count++;
           temp[i]*=-1;
      
            temp[i+1]*=-1;
           
        }
        
    }
      if(count<=k) {
        int i=0;
        for( i=0; i<nums.size(); i++) {
            if(temp[i]==-1) continue;
            else {
                break;
            }
        }
        if(i==temp.size()) return true;
        
    }

    return false;
       
    }
};