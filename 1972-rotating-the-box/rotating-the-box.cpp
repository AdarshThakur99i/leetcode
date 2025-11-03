class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        vector<vector<char>> ans(boxGrid[0].size(),vector<char>(boxGrid.size(),'.'));
int cnt=0;
int n=boxGrid[0].size();
int m=boxGrid.size();
         for(int i=0; i<boxGrid.size(); i++) {
            for(int j=0; j<boxGrid[0].size(); j++) {
                if(boxGrid[i][j]=='#') {
                    cnt++;
                    boxGrid[i][j]='.';
                }
                 if(boxGrid[i][j]=='*' || j==n-1) {
                           int start = (boxGrid[i][j] == '*') ? j - 1 : j;
                        for(int k=start; k>=0; k--) {
                             if (boxGrid[i][k] == '*') break;
                            if(cnt==0) break;
                               boxGrid[i][k]='#';
                               cnt--;

                        }
                }
            }
            cnt=0;
         }

         for(int i=0; i<boxGrid.size(); i++) {
            for(int j=0; j<boxGrid[0].size(); j++) {
                ans[j][m-i-1]=boxGrid[i][j];
            }
         }
         return ans;
    }
}; 