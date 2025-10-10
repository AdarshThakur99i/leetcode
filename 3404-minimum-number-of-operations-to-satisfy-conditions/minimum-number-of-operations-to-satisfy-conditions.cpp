class Solution {
public:
int m;
int n;

    int check(int j,int k,vector<vector<int>> &grid,vector<vector<int>>& dp) {
         if(j>= n) return 0;
         if(dp[j][k]!=-1) return dp[j][k];
       int cost=0;
    int ans=INT_MAX;
         for(int i=0; i<m; i++) {
            if(grid[i][j]!=k) {
                cost++;
            }
         }

         for(int i=0; i<=9; i++)  {
            if(i!=k) {
                ans=min(ans,cost+check(j+1,i,grid,dp));
            }
         }

         return dp[j][k]=ans;
    }
    int minimumOperations(vector<vector<int>>& grid) {
        if(grid.size()==0) return 0;
        m=grid.size();
        n=grid[0].size();
        int cost=INT_MAX;
        vector<vector<int>> dp(n,vector<int>(10,-1));
             for(int i=0; i<=9; i++) {
                   cost=min(cost,check(0,i,grid,dp));
             }

             return cost;
    }
};