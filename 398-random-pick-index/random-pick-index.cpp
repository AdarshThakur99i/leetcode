class Solution {
public:
vector<int> ans;  
    Solution(vector<int>& nums) {
        ans=nums;
     
    }
    
    int pick(int target) {
       int j=0;
       int answ=-1;
       for(int i=0; i<ans.size(); i++) {
        if(ans[i]==target) {
            j++;
            if(rand() % j ==0) {
                answ=i;
            }
        }
       }
       return answ;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */