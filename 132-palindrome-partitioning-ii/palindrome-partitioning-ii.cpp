class Solution {
public:

// bool isPalindrom(string s,int i,int j) {
//     while(i<=j) {
//         if(s[i]!=s[j]) {
//             return false;
//         }
//         i++;
//         j--;
//     }
//     return true;
// }
//   int check(string s,int i,int j,vector<vector<int>>& dp) 
//   {
    
//     if(dp[i][j]!=-1) {
//         return dp[i][j];
//     }
//      if(isPalindrom(s,i,j)) {
//         return 0;
//      }
//      int mini=INT_MAX;
//      for(int k=i; k<=j-1; k++) {
//           int temp=1+check(s,i,k,dp)+check(s,k+1,j,dp);
//           mini=min(temp,mini);
//      }
//     return dp[i][j]=mini;
//   }
    int minCut(string s) {
        if(s.size()==1) return 0;
        int cnt=0;
        vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),false));
        for(int i=0; i<s.size(); i++) {
            dp[i][i]=true;
        }
        for(int l=2; l<=s.size(); l++) {
            for(int i=0; i+l-1<s.size(); i++) {
                int j=i+l-1;

                 if(i+1==j && s[i]==s[j]) {
                    dp[i][j]=true;
                }
                else {
                 dp[i][j]=(s[i]==s[j] && dp[i+1][j-1]);
                }

            }
        }
        vector<int> t(s.size());
        for(int k=0; k<t.size(); k++) {
            if(dp[0][k]) {
                t[k]=0;
            }
            else {
                t[k] = INT_MAX;
                for(int i=0; i<k; i++) {
                    if(dp[i+1][k]==true && 1+ t[i]<t[k]) {
                        t[k]=1+t[i];
                    }
                }
            }
        }
        return t[s.size()-1];
       
    }
};