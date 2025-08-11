class Solution {
public:
    int check(vector<int>& temp,int i,vector<int> &dp) {
        if(i<0 || i>=temp.size()) return 0;
     if(temp[i]==-1) return 0;
     if(dp[i]!=-1) return dp[i];
        int x=temp[i];
        temp[i]=-1;
        int res=1+check(temp,x,dp);

        return dp[i]=res;
    }
    int arrayNesting(vector<int>& nums) {
        
        int i=0;
        int res=0;
        vector<int> dp(nums.size(),-1);
        while(i>=0 && i<nums.size()) {
          if (dp[i] == -1) {
                vector<int> temp = nums;
                res = max(res, check(temp, i, dp));
            }

        i++;
        }
     
        return res;
    }
};