class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int mini=INT_MAX;
        set<int> st;
        if(x==0) return 0;
        int ans=INT_MAX;
        for(int i=x; i< nums.size(); i++) {
            if(i-x  >=0) st.insert(nums[i-x]);

               
               auto idx=st.lower_bound(nums[i]);
               if(idx != st.end()) {
ans=min(ans,abs(*idx-nums[i]));
               }
                if(idx != st.begin()) {
                    idx--;
                    ans=min(ans,abs(*idx-nums[i]));
                } 
        }
        return ans==INT_MAX ?0:ans;
    }
};