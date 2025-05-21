class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
         vector<vector<int>> vis=matrix;

       for(int i=0; i<matrix.size(); i++) {
        for(int j=0; j<matrix[0].size(); j++) {
            if(vis[i][j]==0) {
           for(int k=0; k<matrix.size(); k++) {
            matrix[k][j]=0;
           }

           for(int k=0; k<matrix[0].size(); k++) {
            matrix[i][k]=0;
           }

            }
        }
       }
        
     
        }
    
};