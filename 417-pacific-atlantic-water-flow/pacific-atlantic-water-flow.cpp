class Solution {
public:
    void dfs(int i,int j,vector<vector<int>> &vis,vector<vector<int>> &heights) {
        int m=heights.size(); int n=heights[0].size();     
        vis[i][j]=1;
        int delRow[]={1,0,-1,0};
        int delCol[]={0,1,0,-1};
        for(int k=0; k<4; k++) {
            int newRow=i+delRow[k];
            int newCol=j+delCol[k];
                  if (newRow >= 0 && newCol >= 0 && newRow < m && newCol < n && !vis[newRow][newCol]) {
                    if(heights[newRow][newCol]>=heights[i][j]) {
                dfs(newRow, newCol, vis, heights); }
            } 
        

        }

       
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
            
                vector<vector<int>> ans;

                vector<vector<int>> isAtlantic(heights.size(),vector<int>(heights[0].size(),0));
                vector<vector<int>> isPacific(heights.size(),vector<int>(heights[0].size(),0));

                for(int i=0; i<heights[0].size(); i++) {
                    dfs(heights.size()-1,i,isAtlantic,heights);

                }
                for(int i=0; i<heights.size(); i++) {
                    dfs(i,heights[0].size()-1,isAtlantic,heights);

                }
                  for(int i=0; i<heights[0].size(); i++) {
                    dfs(0,i,isPacific,heights);

                }
                for(int i=0; i<heights.size(); i++) {
                    dfs(i,0,isPacific,heights);

                }
                for(int i=0; i<heights.size(); i++) {
                    for(int j=0; j<heights[0].size(); j++) {
               
                           if(isAtlantic[i][j]==1 && isPacific[i][j]==1) {
                            ans.push_back({i,j});}
  
                    }
                }
            return ans;
    }
}; 