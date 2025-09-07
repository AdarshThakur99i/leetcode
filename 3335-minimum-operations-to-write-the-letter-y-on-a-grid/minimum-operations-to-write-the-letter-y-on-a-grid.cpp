class Solution {
public:
   int check(int cntin,int cntout,vector<vector<int>>& grid) {
    int ans=0;
             for(int i=0; i<grid.size(); i++) {
                for(int j=0; j<grid[0].size(); j++) {

                    if((i==j && i<=grid.size()/2) || (j==grid[0].size()/2 && i>=grid.size()/2) || (i+j == grid.size()-1 && i<=grid.size()/2)) {
                        if(grid[i][j]!=cntin) {
                            ans++;
                        }
                    }
                    else {
                        if(grid[i][j]!=cntout) {
                            ans++;
                        }
                    }
                }
             }
             return ans;
   }
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int ans=INT_MAX;
          for(int cntin=0; cntin<3; cntin++) {
            for(int cntout=0; cntout<3; cntout++) {
                if(cntin==cntout) continue;
                ans=min(ans,check(cntin,cntout,grid));
            }
          }
        

       
return ans;
    }
};