class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(begin(points),end(points),[](const vector<int>& a,const vector<int>& b) {
            return a[1]<b[1];
        });
        if(points.size()==1) return 1;
        long long start=points[0][0];
        long long end=points[0][1];
        int cnt=1;
        int i=1;
     
      while(i<points.size()) {
            if(end < points[i][0]) {
                cnt++;
                end=points[i][1];
            }
            i++;
      }
        return cnt;
    }
};