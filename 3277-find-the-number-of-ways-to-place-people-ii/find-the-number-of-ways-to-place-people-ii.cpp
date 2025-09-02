class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
int cnt=0;
        sort(begin(points),end(points),[](const vector<int>& a,const vector<int>& b) {
            if(a[0]==b[0]) return a[1]>b[1];
                    return a[0]<b[0];
        });
          for(int i=0; i<points.size(); i++) {
            int y=INT_MIN;
            int a=points[i][0];
            int b=points[i][1];
            for(int j=i+1; j<points.size(); j++) {
                  int c=points[j][0];
                  int d=points[j][1];
                if(b>=d && y<d) {
                    cnt++;
                    y=d;
                }
              
            }
          }

          return cnt;
    }
};