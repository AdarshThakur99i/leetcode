class Solution {
public:
    int check(string word1,string word2,int i,int j,vector<vector<int>> &dp) {
        if(i>=word1.size() || j>=word2.size()) {
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];

        int take=0;
        if(word1[i]==word2[j]) {
            take=1+check(word1,word2,i+1,j+1,dp);
        }
       int not_take1=check(word1,word2,i+1,j,dp);
       int not_take2=check(word1,word2,i,j+1,dp);

       return dp[i][j]=max({take,not_take1,not_take2});
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(),vector<int>(word2.size(),-1));
        int res=check(word1,word2,0,0,dp);
        int m=word1.size();
        int n=word2.size();
       int cnt=0;
         cnt+=abs(m-res)+abs(n-res);
        return cnt;
    }
};