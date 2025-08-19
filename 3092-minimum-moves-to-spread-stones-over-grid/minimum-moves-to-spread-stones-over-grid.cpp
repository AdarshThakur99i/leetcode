class Solution {
public:
vector<pair<int,int>> empty;
vector<pair<int,int>> extra;
int ans=INT_MAX;
    void check(int idx,int cost,vector<int> &vis) {
      if(idx==empty.size()) {
        ans=min(ans,cost);
        return;
      }
     int i=empty[idx].first;
     int j=empty[idx].second;
     for(int k=0; k<extra.size(); k++) {
          if(!vis[k]) {
            vis[k]=1;
            int sx=extra[k].first;
            int sy=extra[k].second;
            int dis= abs(sx-i)+abs(sy-j);
            check(idx+1,cost+dis,vis);
            vis[k]=0;
          }
     }
    }
    int minimumMoves(vector<vector<int>>& grid) {
       for(int i=0; i<grid.size(); i++) {
        for(int j=0; j<grid[0].size(); j++) {
            if(grid[i][j]==0) {
                empty.push_back({i,j});
            }
            else if(grid[i][j]>1) {

                for(int k=1; k<grid[i][j]; k++) {
                    extra.push_back({i,j});
                }
            }
        }
       }

       vector<int> vis(extra.size(),0);
       check(0,0,vis);
        return ans;
    }
};