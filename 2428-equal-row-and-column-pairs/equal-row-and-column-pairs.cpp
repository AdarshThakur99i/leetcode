class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int cnt=0;
        for(int i=0; i<grid.size(); i++) {
            int j=0;
             for(int k=0; k<grid.size(); k++) {
            for( j=0; j<grid[0].size(); j++) {
                 if(grid[i][j]!=grid[j][k]) {
                    break;
                 }
                      
            }
            if(j==grid.size()) cnt++;
           
             }
               }
                      return cnt;
    }
};