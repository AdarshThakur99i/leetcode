class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
     
        queue<pair<int,int>> q;
        for(int i=0; i<mat.size(); i++) {
            for(int j=0; j<mat[0].size(); j++) {
                if(mat[i][j]==1) mat[i][j]=-1;
                else {
                    q.push({i,j});
                }
            }
        }
        int delRow[]={1,0,-1,0};
        int delCol[]={0,1,0,-1};
        while(!q.empty()) {
            auto x=q.front();
            q.pop();
            int i=x.first;
            int j=x.second;
            for(int k=0; k<4; k++) {
                int newRow=i+delRow[k];
                int newCol=j+delCol[k];
                if(newRow<0 || newCol<0 || newRow>=m || newCol>=n || mat[newRow][newCol]!=-1) continue;
                mat[newRow][newCol]=mat[i][j]+1;
                q.push({newRow,newCol});

            }
            
        }
           return mat;
    }
};