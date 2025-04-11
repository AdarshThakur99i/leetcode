class Solution {
public:


    bool check(string s1,string s2,string s3,int i,int j,int k,string temp1,vector<vector<int>> &dp) {

        if(k==s3.size()) {
if(temp1==s3) return (i==s1.size() && j==s2.size());
else return false;

        }

        if(dp[i][j]!=-1) return dp[i][j];


      
        bool s1same=(i<s1.size() && s1[i]==s3[k])?check(s1,s2,s3,i+1,j,k+1,temp1+s1[i],dp):false;

        bool s2same=(j<s2.size() && s2[j]==s3[k])?check(s1,s2,s3,i,j+1,k+1,temp1+s2[j],dp):false;


        return dp[i][j]=(s1same||s2same);
    }
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        int i=0;
        int j=0;
        int k=0;
        string temp1="";
      
        return check(s1,s2,s3,i,j,k,temp1,dp);
        
    }
};