class Solution {
public:
    void sortColors(vector<int>& nums) {
      int col1=0;

int col2=0;
int col3=0;
for(int i=0; i<nums.size(); i++) {
    if(nums[i]==0) {
        col1++;
    }
    else if(nums[i]==1) {
        col2++;
    }
    else {
        col3++;
    }
}

  
  for(int i=0; i<nums.size(); i++) {
        if(col1>0) {
            nums[i]=0;
            col1--;
            continue;
        }
         if(col2>0) {
            nums[i]=1;
            col2--;
            continue;
        }
        if(col3>0) {
            nums[i]=2;
            col3--;
            continue;
        }
        

        


  }
      
    }
};