class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(begin(points),end(points));
        int cnt=1;
   
        int initial=points[0][0];
        for(int i=1; i<points.size(); i++) {
             int x=points[i][0];
            if(x <= (initial+w)) {
                continue;
            }
            else {
                   cnt++;
                   initial=x;
            }
        }
        return cnt;
    }
    
};