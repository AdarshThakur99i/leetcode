class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         if(intervals.size()==1) return intervals; 
         sort(begin(intervals),end(intervals),[](const vector<int> &a, const vector<int> &b) {
            return a[0]<b[0];
         });  int start=intervals[0][0];
        int end=intervals[0][1];
    
        vector<vector<int>> ans;
        for(int i=1; i<intervals.size(); i++) {
         
             if(intervals[i][0]<=end) {
              end=max(intervals[i][1],end);
             }
             else {
                ans.push_back({start,end});
               
                    start=intervals[i][0];
                    end=intervals[i][1];
                   
                
             } if(i+1 == intervals.size()) {
                        ans.push_back({start,end});
                    }

        }
        return ans;
    }
};