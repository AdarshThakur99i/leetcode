class Solution {
public:
const int MOD=1e9+7;
    void countStates(string currState,string prevState,vector<string> &result,int m) {
           if(currState.size()==m) {
            result.push_back(currState);
            return;
           }
          for(char ch: {'R','G','B'}) {
            string x=string(1,ch);
             if( x ==prevState) {
                continue;
             }

             countStates(currState+x,x,result,m);

          }

    }

    int solve(int remaining,int prev,int m,vector<string> &result,vector<vector<int>> &dp) {
        if(remaining==0) {
            return 1;
        }
        if(dp[remaining][prev]!=-1) {
            return dp[remaining][prev];
        } 
        int ways=0;
         string prevState=result[prev];
         for(int i=0; i<result.size(); i++) {
            if(i==prev) continue;
            string currstate=result[i];
            bool valid=true;
            for(int j=0; j<m; j++) {
             if(prevState[j]==currstate[j]) {
                valid=false;
                break;
             }

            }
            if(valid==true) {
                ways=(ways+solve(remaining-1,i,m,result,dp))%MOD;

            }
            
         }

         return dp[remaining][prev]=ways;

    }
    int colorTheGrid(int m, int n) {
        vector<string> result;
        countStates("","",result,m);
int ans=0;

   vector<vector<int>> dp(n+1,vector<int>(result.size(),-1));
        for(int i=0; i<result.size(); i++) {

           ans=(ans+solve(n-1,i,m,result,dp))%MOD;

        }

        return ans;

    }
};