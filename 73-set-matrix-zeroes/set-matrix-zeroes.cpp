class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
          vector<vector<int>> used(matrix.size(),vector<int>(matrix[0].size(),0));
          for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                if(matrix[i][j]==0 && used[i][j]==0) {
                    used[i][j]=1;
                   
                    int p=0;
                    while(p<matrix[0].size()) {
                        if(matrix[i][p]!=0) {
                        matrix[i][p]=0;
                        used[i][p]=1;}
                        p++;
                    }
                   int k=0;
                    
                    while(k<matrix.size()) {
                        if(matrix[k][j]!=0) {
                        matrix[k][j]=0;
                        used[k][j]=1; }
                        k++;
                    }


                }
            }
          }
     
        }
    
};