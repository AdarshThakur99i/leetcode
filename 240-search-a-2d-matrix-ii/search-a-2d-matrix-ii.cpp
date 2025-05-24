class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size()-1;
        int n=matrix[0].size()-1;
        
         int i=0;
         int j=n;
         while(i>=0 && j>=0 && i<matrix.size() && j<matrix[0].size()) {
            if(target>matrix[i][j] ) {
                i++;
            }
            else if(target <matrix[i][j]) {
                j--;
            }
            else {
                return true;
            }
         }

       return false;
    }
};