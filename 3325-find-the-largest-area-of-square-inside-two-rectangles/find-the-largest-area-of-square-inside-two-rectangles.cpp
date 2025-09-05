class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
         int maxi=INT_MIN;
         for(int i=0; i<bottomLeft.size(); i++) {
                 int stx=bottomLeft[i][0];
                 int endx=topRight[i][0];
                 int sty=bottomLeft[i][1];
                 int endy=topRight[i][1];
                 
            for(int j=i+1; j<topRight.size(); j++) {
                
                 int st2x=bottomLeft[j][0];
                 int end2x=topRight[j][0];
                 int st2y=bottomLeft[j][1];
                 int end2y=topRight[j][1];

                  int ix2=min(endx,end2x);
                  int iy1=max(st2y,sty);
                  int ix1=max(stx,st2x);
                  int iy2=min(end2y,endy);

                  if(ix1<ix2 && iy1<iy2) {
                    int mini=min(ix2-ix1,iy2-iy1);
                    maxi=max(maxi,mini);
                  }
         }
         }
        
          return maxi==INT_MIN ? 0 : (1LL*maxi*maxi);
    }
};