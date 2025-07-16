class Solution {
public:
  void dfs(vector<vector<char>> &board,vector<vector<int>> &vis,int i,int j) {

    vis[i][j]=1;
    int delRow[]={1,0,-1,0};
    int delCol[]={0,1,0,-1};
    for(int k=0; k<4; k++) {
        int newRow=i+delRow[k];
        int newCol=j+delCol[k];
        if(newRow>=0 && newCol>=0 && newRow<board.size() && newCol<board[0].size() && !vis[newRow][newCol] && board[newRow][newCol]=='X') {
            dfs(board,vis,newRow,newCol);
        }
    }
  }
    int countBattleships(vector<vector<char>>& board) {
        vector<vector<int>> vis(board.size(),vector<int>(board[0].size(),0));
        int cnt=0;
         for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if(board[i][j]=='X' && !vis[i][j]) {
                    dfs(board,vis,i,j);
                    cnt++;
                }
            }
         }
         return cnt;
    }
};