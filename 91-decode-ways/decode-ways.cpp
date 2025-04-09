class Solution {
public:

    int check(string s,unordered_map<string,int> mp,int i,vector<int> &dp) {
if(i>=s.size()) {
    return 1;
}
    if(dp[i] !=-1) return dp[i];
          int take1=0;
          string p(1,s[i]);
           if(mp[p]>0) {
            take1=check(s,mp,i+1,dp);

           }
        
           
           int take2=0;
        if(i+1<s.size()){
           string x=s.substr(i,2);
           if(mp[x]>0) {
            take2=check(s,mp,i+2,dp);
           }}


           return dp[i]=take1+take2;

          
          
    }
    int numDecodings(string s) {
        unordered_map<string,int> mp;
        vector<int> dp(s.size(),-1);

        for(int i=1; i<27; i++) {
            string x=to_string(i);
            mp[x]=1;
        }
        int x=check(s,mp,0,dp);

        return x;


    }
};