class Solution {
public:

   int check(int start,int end,vector<vector<int>> &dp) {
         if(start>end) return 1;

        if(dp[start][end]!=-1) return dp[start][end];
int total=0;
        for(int i=start; i<=end; i++) {
              int left=check(start,i-1,dp);

              int right=check(i+1,end,dp);


              total+=left*right;
             
        }

        return dp[start][end]=total;
 
   }
    int numTrees(int n) {
        int res=0;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        return check(1,n,dp);
        
    }
};  