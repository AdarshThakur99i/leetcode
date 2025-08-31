class Solution {
public:
  vector<vector<int>> dir={{1,1},{1,-1},{-1,-1},{-1,1}};
    int solve(int i,int j,int d,bool canTurn,int val,vector<vector<int>>& grid) {
              
              int newi=i+dir[d][0];
              int newc=j+dir[d][1];
              int keepmoving=0;
              int move=0;
              int res=0;
              if(newi<grid.size() && newi >=0 && newc < grid[0].size() && newc>=0 && grid[newi][newc]==val)  {
                        keepmoving=1+solve(newi,newc,d,canTurn,(val==2)?0:2,grid);
                       if(canTurn==true) {
                        move=max(keepmoving,1+solve(newi,newc,(d+1)%4,false,(val==2)?0:2,grid));
                       }
                       res=max(move,keepmoving);
              }
              return res;
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int res=0;
          for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j]==1) {
                     for(int d=0; d<=3; d++) {
                       res=max(res,1+solve(i,j,d,true,2,grid));
                     }
                }
               
            }
          }
          return res;
    }
};