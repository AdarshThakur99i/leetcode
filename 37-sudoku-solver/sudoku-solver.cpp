class Solution {
public:
vector<vector<char>> ans;
    void solve(vector<vector<char>> &board,int currrow,int currcol) {
              if(!ans.empty()) return;
                if(currrow==9) {
                    ans=board;
                    return;
                }
              

                 vector<int> vis(10,0);
                if((board[currrow][currcol]) != '.') {
                       if(currcol==(board[0].size()-1)) {
                            solve(board,currrow+1,0);
                        }
                        else {
                            solve(board,currrow,currcol+1);
                        }
                        return;
                }
                int startRow = (currrow / 3) * 3;
int startCol = (currcol / 3) * 3;
for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
        char ch = board[startRow + i][startCol + j];
        if (isdigit(ch)) {
            vis[ch - '0']++;
        }
    }
}

                 for(int j=0; j<board[0].size(); j++) {
                    if((board[currrow][j]) != '.') {
                        int x=(board[currrow][j]-'0');
                        vis[x]++;
                    }
                 }
                  for(int i=0; i<board.size(); i++) {
                    if((board[i][currcol])!='.') {
                        int x=(board[i][currcol])-'0';
                        vis[x]++;
                    }
                 }
                  
                 for(int i=1; i<=9; i++) {
                    if(!vis[i]) {

                        board[currrow][currcol] = '0' + i;
                        if(currcol==(board[0].size()-1)) {
                            solve(board,currrow+1,0);
                        }
                        else {
                            solve(board,currrow,currcol+1);
                        }
                       board[currrow][currcol]='.';                        
                    }
                 }

    }
    void solveSudoku(vector<vector<char>>& board) {

        solve(board,0,0);
        board=ans;
        
    }
};