class Solution {
public:

   int check(vector<int>& nums,int i,int j,int score,vector<vector<int>>& dp) {
       
    if(i>=j) return 0;
 
   if(dp[i][j]!=-1) return dp[i][j];
    int takefirst2=0;
    if(i+1 <=j && (nums[i]+nums[i+1])==score) {
        
            takefirst2=1+check(nums,i+2,j,nums[i]+nums[i+1],dp);
    }

    int takelast2=0;
    if(j-1 >=i && (nums[j]+nums[j-1])==score) {
        
        takelast2=1+check(nums,i,j-2,nums[j]+nums[j-1],dp);
    }
    int takeoneone=0;
    if((nums[i]+nums[j])==score) {
        takeoneone=1+check(nums,i+1,j-1,nums[i]+nums[j],dp);

    }

    return dp[i][j]=max({takefirst2,takelast2,takeoneone});
   }
    int maxOperations(vector<int>& nums) {
       
     
     int n=nums.size();
       vector<pair<int,int>> state= {
        {0,n-1},
        {0,1},
        {n-1,n-2}
       };
       int ans=INT_MIN;
       for(auto [a,b]:state) {
        //    if(a < 0 || b >= n || a >= b) continue; 
        int score=nums[a]+nums[b];
           vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
           ans=max(ans,check(nums,0,n-1,score,dp));
           
       }
        return ans;

    }
};