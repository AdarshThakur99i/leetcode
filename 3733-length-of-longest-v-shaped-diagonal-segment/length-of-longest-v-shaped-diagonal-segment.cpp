class Solution {
public:
vector<vector<int>> dir={{1,1},{1,-1},{-1,-1},{-1,1}};
    int check(vector<vector<int>>& grid,int i,int j,bool canTurn ,int d,int val ) {
              
              int newr=i+dir[d][0];
              int newc=j+dir[d][1];
              int keepmoving=0;
              int move=0;
              int res=0;
            if(newr>=0 && newr<grid.size() && newc >=0 && newc < grid[0].size() && grid[newr][newc] == val) {
                            keepmoving=1+check(grid,newr,newc,canTurn,d,(val==2)?0:2);
                           if(canTurn==true) {
                                    move =max(keepmoving,1+check(grid,newr,newc,false,(d+1)%4,(val==2)?0:2));
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
res=max(res,1+check(grid,i,j,true,d,2));
                }
                      

            }}
          }

          return res;
    }
};