class Solution {
public:
vector<int> ans;
    Solution(vector<int>& nums) {
        ans=nums;
    }
    
    vector<int> reset() {
        return ans;
        
    }
    
    vector<int> shuffle() {
        vector<int> temp=ans;
        for(int i=temp.size()-1; i>=0; i--) {
            int j=rand() % (i+1);
            swap(temp[i],temp[j]);
        }
        return temp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */