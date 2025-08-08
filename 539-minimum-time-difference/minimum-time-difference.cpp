class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
           vector<int> minutes;
           for(int i=0; i<timePoints.size(); i++) {
               int a=stoi(timePoints[i].substr(0,2));
               int b=stoi(timePoints[i].substr(3,2));
               minutes.push_back(a*60+b);
           }
           sort(begin(minutes),end(minutes));
            int mini=INT_MAX;
            for(int i=1; i<minutes.size(); i++) {
              mini=min(mini,(minutes[i]-minutes[i-1]));
            }

            int circular=1440-(minutes.back()-minutes[0]);
            mini=min(mini,circular);
            return (mini==INT_MAX) ? 0: mini;
    }
};
