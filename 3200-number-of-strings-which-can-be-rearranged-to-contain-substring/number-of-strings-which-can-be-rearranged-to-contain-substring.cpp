class Solution {
public:
const int MOD=1e9+7;
int dp[100001][2][3][2];
long long check(int n,int l,int e,int t,int i) {
if(i==n) {
    if(l==1 && e==2 && t==1) return 1;
    return 0;
}

if(dp[i][l][e][t] != -1) return dp[i][l][e][t];
long long ans=0;
    ans+=check(n,1,e,t,i+1)%MOD;
    ans+=check(n,l,min(2,e+1),t,i+1)%MOD;
    ans+=check(n,l,e,1,i+1)%MOD;
    ans+= 23*check(n,l,e,t,i+1)%MOD;

    return dp[i][l][e][t]=ans%MOD;
}
    int stringCount(int n) {
        memset(dp,-1,sizeof(dp));
        // long long x=n-4;
        // long long pro=1;
        // while(x>0) {
        //     pro=(pro*26);
        //     x--;
        // }
        // return (pro*12) %MOD;
        return check(n,0,0,0,0);
    }
};