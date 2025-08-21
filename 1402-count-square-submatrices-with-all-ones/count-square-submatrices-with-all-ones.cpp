class Solution {
public:
vector<vector<int>> dp;
   int check(vector<vector<int>>& matrix,int i,int j) {
    if( i>=matrix.size() || j>=matrix[0].size() || matrix[i][j]==0) return 0;
  if(dp[i][j]!=-1) return dp[i][j];
    int right=check(matrix,i,j+1);
    int bottom=check(matrix,i+1,j);
    int bottom_right=check(matrix,i+1,j+1);

    return dp[i][j]=1+min({right,bottom,bottom_right});

   }
    int countSquares(vector<vector<int>>& matrix) {
        int cnt=0;
   dp.assign(matrix.size(),vector<int>(matrix[0].size(),-1));
        for(int i=0; i<matrix.size(); i++) {
          for(int j=0; j<matrix[0].size(); j++) {
            if(matrix[i][j]==1) {
               int n= check(matrix,i,j);
               cnt += n;
            }
          }
        }
        return cnt;
    }
};