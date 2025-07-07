class Solution {
public:
int check(int n,vector<vector<int>> &matrix) {

    int cnt=0;
    int m=matrix[0].size();
      for(int i=0; i<matrix.size(); i++) {
              if(matrix[i][m-1]<=n) {
                cnt+=m;

              }
              else if(matrix[i][0]<=n) {
                cnt+= upper_bound(begin(matrix[i]),end(matrix[i]),n) - begin(matrix[i]);
              }

      }
    return cnt;
}
    int kthSmallest(vector<vector<int>>& matrix, int k) {
           int i=0;
           int m=matrix.size();
int n=matrix[0].size();
int left = matrix[0][0];
int right = matrix[m-1][n-1];
int ans=0;
           while(left<=right)  {
            int mid=left + (right-left)/2;

            if(check(mid,matrix)>=k) {
                ans=mid;
                right=mid-1;
            }
            else {
                   left=mid+1;
            }
   

           }
           return ans;

    }
}; 