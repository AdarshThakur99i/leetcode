class Solution {
public:

    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        long long pro=1;
          vector<long long> temp;
          for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                temp.push_back((long long)grid[i][j]);
            }
          }
          long long pref=1;
          long long suff=1;
          vector<long long> res(temp.size(),0);
          for(int i=0; i<temp.size(); i++) {
           res[i]=pref;
            pref=(pref*temp[i])%12345;
          }
          for(int i=temp.size()-1; i>=0; i--) {
            res[i]=(res[i]*suff)%12345;
            suff=(suff*temp[i]%12345);
          }
          int idx=0;
          vector<vector<int>> ans=grid;
          for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<ans[0].size(); j++) {
                ans[i][j]=res[idx];
                idx++;
            }
          }
        return ans;
    }
};  