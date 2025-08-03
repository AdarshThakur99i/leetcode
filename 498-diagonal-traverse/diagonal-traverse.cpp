class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
      int i=0;
      int j=0;
       int m=mat.size();
       int n=mat[0].size();
        vector<int> ans;
       
     
       bool upward=true;
      while(ans.size()<m*n) {
        ans.push_back(mat[i][j]);
            if(upward) {
                if(j==n-1) {
                    i++;
                    upward=false;
                }
                else if(i==0) {
                    j++;
                    upward=false;

                }
                else{
            i--;
            j++;}
       }
       else {
        if(i==m-1) {
            j++;
            upward=true;
        }
        else if(j==0) {
            i++;
            upward=true;
        }
        else {
            i++;
            j--;
        }
       } 
      }
      return ans;
    }
};