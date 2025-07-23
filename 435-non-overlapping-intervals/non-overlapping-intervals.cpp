class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
         sort(begin(intervals),end(intervals), [](const vector<int> &a,const vector<int> &b) {
                 return a[1]<b[1];
         });
         int end=intervals[0][1];
         int cnt=0;
         for(int i=1; i<intervals.size(); i++) {
               if(intervals[i][0] <end) {
             cnt++;
               }
               else {
                end=intervals[i][1];
               }
         }
         return cnt;
    }
};