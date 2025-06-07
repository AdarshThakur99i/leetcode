class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        int delRow[]={1,1,0,-1,-1,-1,0,1};
        int delCol[]={0,1,1,1,0,-1,-1,-1};
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                int temp=0;
        
               for(int k=0; k<8; k++) {
                int newRow=i+delRow[k];
                int newCol=j+delCol[k];
                if(newCol>=0 && newRow>=0 && newCol<board[0].size() && newRow<board.size()) {
                if(board[newRow][newCol]==1 || board[newRow][newCol]==2) {
                    temp++;
                }

                }
               }
              if(board[i][j]==1) {
                if(temp<2 || temp>3) {
                    board[i][j]=2;
                }
              }
              else {
                if(temp==3) board[i][j]=-1;
              }
            }
        }
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if(board[i][j]==2) board[i][j]=0;
                else if(board[i][j]==-1) board[i][j]=1;
            }
        }
    }
};