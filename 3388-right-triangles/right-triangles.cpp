class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        long long cnt=0;
          vector<int> col(grid[0].size(),0);
          vector<int> row(grid.size(),0);
         for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j]!=1) continue;
                    col[j]++;
                    row[i]++;
            }
         }
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++ ) {
                if(grid[i][j]!=1) continue;
                int totalColOne=col[j]-1;
                int totalRowOne=row[i]-1;
                cnt += totalColOne*totalRowOne;


            }
        }

        return cnt;
    }
};