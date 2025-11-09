class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        const long long NEG = LLONG_MIN/4;               // safe sentinel
        int K = k + 1;
        // dp[i][j][c] = max sum reaching (i,j) with cost c (includes grid[i][j])
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(K, NEG)));

        int startCost = (grid[0][0] == 0) ? 0 : 1;
        if (startCost > k) return -1;
        dp[0][0][startCost] = grid[0][0];

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int cst = 0; cst <= k; ++cst) {
                    if (dp[i][j][cst] == NEG) continue;
                    long long cur = dp[i][j][cst];

                    if (i + 1 < m) {
                        int add = (grid[i+1][j] == 0) ? 0 : 1;
                        if (cst + add <= k) {
                            dp[i+1][j][cst+add] = max(dp[i+1][j][cst+add], cur + grid[i+1][j]);
                        }
                    }
                    if (j + 1 < n) {
                        int add = (grid[i][j+1] == 0) ? 0 : 1;
                        if (cst + add <= k) {
                           
                            dp[i][j+1][cst+add] = max(dp[i][j+1][cst+add], cur + grid[i][j+1]);
                        }
                    }
                }
            }
        }

        long long ans = NEG;
        for (int c = 0; c <= k; ++c) ans = max(ans, dp[m-1][n-1][c]);
        return ans == NEG ? -1 : (int)ans;
    }
};
