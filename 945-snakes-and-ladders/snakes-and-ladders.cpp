class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
      vector<int> mini(n*n+1,-1);
      queue<int> q;
      q.push(1);
      mini[1]=0;
      while(!q.empty()) {
       int x=q.front();
       q.pop();
       for(int i=1; i<=6 && x+i <= m*n; i++) {
        int  t=x+i;
        int row=(t-1)/n;
        int col=(t-1)%n;
        int v=board[m-row-1][row%2?n-col-1:col];
        int y=(v>0) ?  v:t;
        if(y==n*n) {
          return mini[x]+1;  
        }
          if(mini[y]==-1) {
           mini[y]=mini[x]+1;
           q.push(y);
          }    
       }
      }
      return -1;
    }
};