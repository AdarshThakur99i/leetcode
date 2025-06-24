class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> temp;
        int n=nums.size();
        vector<int> vis(nums.size(),0);
        for(int i=0; i<nums.size(); i++) {
            for(int j=0; j<nums.size(); j++) {
                 if(abs(i-j) <=k && nums[j]==key) {
                   if(vis[i]==0) {
                    temp.push_back(i);
                    vis[i]=1;
                   }
                 }
            }
        }
        sort(begin(temp),end(temp));

        return temp;
    }
};