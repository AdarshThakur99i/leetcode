class Solution {
public:
   int N;
    vector<int> countOfPairs(int n, int x, int y) {
            vector<vector<int>> adj(n+1,vector<int>(n+1,INT_MAX));
            for(int i=1; i<=n; i++) {
                if(i+1 <=n) {
                adj[i][i+1]=1;
                adj[i+1][i]=1; }
            }

            adj[x][y]=1;
            adj[y][x]=1;

            for(int k=1; k<=n; k++) {
                for(int i=1; i<=n; i++) {
                    for(int j=1;  j<=n; j++) {
                        if(adj[i][k] < INT_MAX && adj[k][j]<INT_MAX) {
                            adj[i][j]=min(adj[i][j],(adj[i][k]+adj[k][j]));
                        }
                    }
                }
            }
            vector<int> res(n,0);
            for(int i=1; i<=n; i++) {
                for(int j=1; j<=n; j++) {
                    if(i!=j && adj[i][j] != INT_MAX) {
                        int val=adj[i][j];
                        res[val-1]++;
                    }
                }
             }
            return res;
               
        
    }
};