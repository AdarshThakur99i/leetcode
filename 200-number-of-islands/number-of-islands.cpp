class Solution {
public:

   void bfs(vector<vector<char>>& grid,vector<vector<bool>> &vis,int i,int j,int &count) {

    queue<pair<int,int>> q;
    int delRow[]={1,0,-1,0};
    int delCol[]={0,1,0,-1};
  vis[i][j]=true;
    q.push({i,j});

    while(!q.empty()) {
        auto x=q.front();
        q.pop();
        int idxi=x.first;
        int idxj=x.second;
         
         for(int k=0; k<4; k++) {
int newRow=idxi + delRow[k];
int newCol=idxj + delCol[k];

         if(newRow>=0 && newRow<grid.size() && newCol<grid[0].size() && newCol>=0 && grid[newRow][newCol]=='1' && !vis[newRow][newCol]) {
            vis[newRow][newCol]=true;
                 q.push({newRow,newCol});
         }
         }

    }
    count++;

   }
    int numIslands(vector<vector<char>>& grid) {

        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),false));

        int count=0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j]=='1' && !vis[i][j]) {
                    bfs(grid,vis,i,j,count);
                }
            }
        }
       
         return count;
    }
    
};