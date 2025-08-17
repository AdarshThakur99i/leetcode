class Solution {
public:

 bool dfs(vector<vector<int>>& grid,int i,int j,int s,vector<vector<int>>& vis,vector<vector<int>> &dist) 
 {
        if(i==grid.size()-1 && j==grid[0].size()-1) {
            return true;
        }
    vis[i][j]=1;
      int delRow[]={1,0,-1,0};
   int delCol[]={0,1,0,-1};
       for(int k=0; k<4; k++) {
        int newRow=i+delRow[k];
        int newCol=j+delCol[k];
        if(newRow>=0 && newCol>=0 && newRow<grid.size() && newCol<grid[0].size() && !vis[newRow][newCol] && dist[newRow][newCol]>=s) {
             if(dfs(grid,newRow,newCol,s,vis,dist)==true) {
                return true;
             };
        }
       }

   

    return false;

 }
    int maximumSafenessFactor(vector<vector<int>>& grid) {

        vector<vector<int>> dist(grid.size(),vector<int> (grid[0].size(),INT_MAX));
         
        queue<pair<int,int>> q;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j]==1) {
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int delRow[]={1,0,-1,0};
        int delCol[]={0,1,0,-1};
        while(!q.empty()) {
         int sz=q.size();
         while(sz--) {
         auto x=q.front();
         q.pop();
         int i=x.first;
         int j=x.second;
        for(int k=0; k<4; k++){
            int newRow=i+delRow[k];
            int newCol=j+delCol[k];
            if(newRow>=0 && newCol>=0 && newRow<grid.size() && newCol<grid[0].size() && dist[newRow][newCol]==INT_MAX) {    
                dist[newRow][newCol]=dist[i][j]+1;
                q.push({newRow,newCol});  
            }
        }  
         }

        }

        int l=0;
        int r=2*(grid.size()-1);
        int ans=0;
        while(l<=r) {
            vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
            int s=l+(r-l)/2;
            if(dist[0][0]>=s && dist[grid.size()-1][grid[0].size()-1]>=s && dfs(grid,0,0,s,vis,dist)) {
                ans=s;
                l=s+1;
            }
            else {
                r=s-1;
            }
        }
        return ans;
     
    }
};