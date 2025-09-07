class Solution {
public:
   
    int countSubmatrices(vector<vector<int>>& grid, int k) {
int ans=0;
        vector<vector<int>> pref(grid.size(),vector<int>(grid[0].size(),0));
           for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                 if(i==0 && j==0) {
                    pref[i][j]=grid[i][j];
                 }
                 else if(i==0) {
                    pref[i][j]=pref[i][j-1]+grid[i][j];
                 }
                 else if(j==0) {
                    pref[i][j]=pref[i-1][j]+grid[i][j];
                 }
                 else {
                        pref[i][j]=pref[i-1][j]+pref[i][j-1]+grid[i][j]-pref[i-1][j-1];
                 }
                 if(pref[i][j]<=k) ans++;
            }
           }
        return ans;
    }
};