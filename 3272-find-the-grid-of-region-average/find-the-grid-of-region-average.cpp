class Solution {
public:
 vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
      vector<vector<int>> grid(image.size(),vector<int> (image[0].size(),0));
        vector<vector<int>> cnt(image.size(),vector<int> (image[0].size(),0));
            for(int i=0; i<image.size(); i++) {
                for(int j=0; j<image[0].size(); j++) {
                    if(i+2 >= image.size() || (j+2) >= image[0].size()) continue;
                    int avg=0;
                    int maxi=INT_MIN;
                    int mini=INT_MAX;
                   bool ok=true;
                     for(int l=i; l<(i+3); l++) {
                        for(int m=j; m<(j+3); m++) {
                            avg += image[l][m];
                           if(l>i) {
                            if(abs(image[l-1][m]-image[l][m]) > threshold) {
                                ok=false;
                                break;
                            }
                          
                           }
                             if(l<(i+2)) {
                                if(abs(image[l+1][m]-image[l][m]) > threshold) {
                                    ok=false;
                                    break;
                                }
                            }
                             if(m<(j+2)) {
                                if(abs(image[l][m+1]-image[l][m]) > threshold) {
                                    ok=false;
                                    break;
                                }
                            }
                             if(m>j) {
                                if(abs(image[l][m-1]-image[l][m]) > threshold) {
                                    ok=false;
                                    break;
                                }
                            }
                        }
                        if(ok==false) break;
                     }
                  if(ok==false) continue;
                     avg=avg/9;
                        for(int l=i; l<(i+3); l++) {
                        for(int m=j; m<(j+3); m++) {
                         
                           
                                grid[l][m]+=avg;
                                cnt[l][m]++;
                        
                        }
                     }
                }
            } 

            for(int i=0; i<grid.size(); i++) {
                for(int j=0; j<grid[0].size(); j++) {
                    if(cnt[i][j]==0) continue;
                    image[i][j]= (grid[i][j])/cnt[i][j];
                }
            }

            return image;
    }
};

