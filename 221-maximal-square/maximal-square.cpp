class Solution {
public:

    int check(vector<vector<char>>& matrix,int i,int j,vector<vector<int>> &dp) {
         if(i>=matrix.size() || j>=matrix[0].size()) {
            return 0;
         }
         if(matrix[i][j]=='0') {
            return 0;
         }
       if(dp[i][j]!=-1) return dp[i][j];

      int right = check(matrix,i,j+1,dp);
      int down=check(matrix,i+1,j,dp);
      int down_right=check(matrix,i+1,j+1,dp);

      return dp[i][j]=1+min({right,down,down_right});

    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans=0;
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                if(matrix[i][j]=='1') {
                    ans=max(check(matrix,i,j,dp),ans);
                }


            }
        }
        return ans*ans;
    }
};