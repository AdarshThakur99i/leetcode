class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int idx=0;
         if (matrix.empty() || matrix[0].empty()) return false;
        int m=matrix.size();
        int n=matrix[0].size();
        int left=0;
        int right=(m*n)-1;
while(left<=right) {
    int mid=left+(right-left)/2;

    if(matrix[mid/n][mid%n]==target) return true;

    else if(matrix[mid/n][mid%n]>target) right=mid-1;

    else {
        left=mid+1;
    }
}
           return false;

    }
};