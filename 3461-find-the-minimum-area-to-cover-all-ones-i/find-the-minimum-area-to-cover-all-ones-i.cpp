class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int left=-1;
        int right=-1;
      for(int j=0; j<grid[0].size(); j++) {
        for(int i=0; i<grid.size(); i++) {
            if(grid[i][j]==1) {
                if(left==-1)   left=j;
                right=j;
            }
        }
      }
      int top=-1;
      int bottom=-1;
        for(int i=0; i<grid.size(); i++) {
        for(int j=0; j<grid[0].size(); j++) {
            if(grid[i][j]==1) {
                if(top==-1)   top=i;
                bottom=i;
            }
        }
      }
        int width=right-left+1;
        int height=bottom-top+1;
        return height*width;
    }
};