class Solution {
public:

    int check(vector<vector<int>> &info,int i,vector<int> &start,vector<int>& dp) {
      if(i>=info.size()) {
        return 0;
      }
if(dp[i]!= -1) return dp[i];
        int not_take=check(info,i+1,start,dp);
         int idx=lower_bound(begin(start),end(start),info[i][1])-begin(start);

         int take=info[i][2]+check(info,idx,start,dp);

         return dp[i]= max(take,not_take);

    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> info;
        vector<int> start;

        for(int i=0; i<startTime.size(); i++) {
            info.push_back({startTime[i],endTime[i],profit[i]});
            start.push_back(startTime[i]);
        }vector<int> dp(start.size(),-1);
    
        sort(begin(info),end(info),[](const vector<int> &a,const vector<int> &b) {
                      return a[0]<b[0];
        });
        sort(begin(start),end(start));
        return check(info,0,start,dp);
    }
};