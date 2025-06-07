class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> temp=board;
        int delRow[]={1,1,0,-1,-1,-1,0,1};
        int delCol[]={0,1,1,1,0,-1,-1,-1};
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                int tempe=0;
                int dead_check=0;
               for(int k=0; k<8; k++) {
                int newRow=i+delRow[k];
                int newCol=j+delCol[k];
                if(newCol>=0 && newRow>=0 && newCol<board[0].size() && newRow<board.size()) {
                 if(temp[i][j]==1) {
                    if(temp[newRow][newCol]==1) tempe++;
                 }
                 else {
                    if(temp[newRow][newCol]==1) dead_check++;
                 }

                }
               }
               if( temp[i][j]==1 && tempe<2) board[i][j]=0;
               else if(temp[i][j]==1 && (tempe==2 || tempe==3)) board[i][j]=1;
               else if(temp[i][j]==1 && tempe>3) board[i][j]=0;
               else if(temp[i][j]==0 && dead_check==3) board[i][j]=1;
            }
        }
    }
};