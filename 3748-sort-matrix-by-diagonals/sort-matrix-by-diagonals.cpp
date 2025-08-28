class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int i=0;
        int j=0;
        int l=grid.size()-1;
        int r=0;
        while(l >=0 && r<=(grid[0].size()-1)) {
              vector<int> temp;
              int currrow=l;
              int finalrow=grid.size()-1;
              int currcol=0;
              int finalcol=r;

              while(currrow<=finalrow && currcol<=finalcol) {
                temp.push_back(grid[currrow][currcol]);
                currrow++;
                currcol++;
              }
              sort(begin(temp),end(temp),greater<int>());
              int idx=0;
                currrow=l;
              finalrow=grid.size()-1;
               currcol=0;
               finalcol=r;
                 while(currrow<=finalrow && currcol<=finalcol) {
              grid[currrow][currcol]=temp[idx++];
                currrow++;
                currcol++;
              }


            l--;
            r++;
        }
        r=grid[0].size()-1;
        l=0;
        while(l<grid.size() && r>0) {
             vector<int> temp;
             int currrow=0;
             int finalrow=l;
             int currcol=r;
             int finalcol=grid[0].size()-1;

             while(currrow<=finalrow && currcol<=finalcol) {
                temp.push_back(grid[currrow][currcol]);
                currrow++;
                currcol++;
             }
              sort(begin(temp),end(temp));
              int idx=0;
                currrow=0;
              finalrow=l;
               currcol=r;
               finalcol=grid[0].size()-1;
                 while(currrow<=finalrow && currcol<=finalcol) {
              grid[currrow][currcol]=temp[idx++];
                currrow++;
                currcol++;
              }
              l++;
              r--;

        }

        return grid;

    }
};