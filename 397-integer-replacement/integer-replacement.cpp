class Solution {
public:
 unordered_map<long, int> dp;
long long check(long long n) {
    if(n==1) return 0;
    if(dp.count(n)) return dp[n];
long long take=0;

    if(n%2==0) {
        take=1+check(n/2);
    }
    else {
        take=1+min(check(n+1),check(n-1));
    }

    return dp[n]=take;
}
    int integerReplacement(int n) {
      
        return check(n);

        
    }
};