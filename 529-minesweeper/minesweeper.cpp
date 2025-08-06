class Solution {
public:

    void dfs(vector<vector<char>> &board,vector<int>& click,int i,int j,int cnt) {
        int delRow[]={1,1,0,-1,-1,-1,0,1};
        int delCol[]={0,1,1,1,0,-1,-1,-1};
cnt=0;
        for(int k=0; k<8; k++) {
            int newRow=i+delRow[k];
            int newCol=j+delCol[k];
            if(newRow>=0 && newRow<board.size() && newCol<board[0].size() && newCol>=0) {
                if(board[newRow][newCol]=='M') cnt++;
               
            }
        }

        if(cnt>=1) {
            board[i][j]='0'+cnt;

        }
        else {
            board[i][j]='B';
             for(int k=0; k<8; k++) {
            int newRow=i+delRow[k];
            int newCol=j+delCol[k];
            if(newRow>=0 && newRow<board.size() && newCol<board[0].size() && newCol>=0 && board[newRow][newCol]=='E') {
                   dfs(board,click,newRow,newCol,cnt);
               
            }
        }
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    
             if(board[click[0]][click[1]] == 'M') {
                board[click[0]][click[1]] ='X';
                return board;
             }

             if(board[click[0]][click[1]] == 'E') {
int cnt=0;
dfs(board,click,click[0],click[1],cnt);


             }
             return board;
    }
};