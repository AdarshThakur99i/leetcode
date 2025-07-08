class Solution {
public:

    int check(vector<vector<int>> &events,int k,int i,vector<vector<int>> &dp) {
           if(k<0) return INT_MIN;
             if(i==events.size()) {
                if(k>=0) {
                    return 0;   }
                return INT_MIN;
             }
            if(dp[i][k]!=-1) {
                return dp[i][k];
            }
   long long take=0;
    long long idx=upper_bound(events.begin()+i+1,events.end(),events[i][1], [](int val,const vector<int> &event) {
        return val<event[0];
    }) - events.begin();
         take=events[i][2] + check(events,k-1,idx,dp); 
        long long not_take=check(events,k,i+1,dp);

        return dp[i][k]=max(take,not_take);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(begin(events),end(events));
        vector<vector<int>> dp(events.size(),vector<int>(k+1,-1));
        return check(events,k,0,dp);
        
    }
};