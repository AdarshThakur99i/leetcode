class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
             vector<int> gap;
              gap.push_back(startTime[0]);
           
              for(int i=1; i<startTime.size(); i++)  {
                gap.push_back(startTime[i]-endTime[i-1]);
            
              }
           
                gap.push_back(eventTime-endTime[endTime.size()-1]);
              
              
             vector<int> maxRight(gap.size(),0);
             vector<int> maxLeft(gap.size(),0);
int n=gap.size()-1;
             for(int i=1; i<gap.size(); i++) {
                 maxLeft[i]=max(gap[i-1],maxLeft[i-1]);
                 maxRight[n-i]=max((gap[n-i+1]),maxRight[n-i+1]);
             }
int res=0;
          for(int i=1; i<gap.size(); i++) {
            int curr=endTime[i-1]-startTime[i-1];
            if(curr <=max(maxLeft[i-1],maxRight[i])) {
                res=max(res,gap[i-1]+gap[i]+curr);
            }
              res=max(res,gap[i-1]+gap[i]);
          }
              
           return res;
    }
};