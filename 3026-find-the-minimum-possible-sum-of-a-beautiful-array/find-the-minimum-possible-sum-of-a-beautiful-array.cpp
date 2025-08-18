class Solution {
public:
const int MOD=1e9+7;
const int INV2=500000004;
    int minimumPossibleSum(int n, int target) {
          int x=target/2;
          int remnums=n-x;
          if(x>=n) {
            long long sum=(1LL*n*(n+1)%MOD *INV2)%MOD;
            return sum;
          }

          long long sum=(1LL * x * (x+1) %MOD  * INV2)%MOD;
long long target1=target;
          if(x==n) return sum;
        
          if(remnums==0) return sum;
         long long n1=(target+remnums-1)%MOD;
         long long temp = ((target1 + n1) % MOD * remnums % MOD * INV2) % MOD;
sum = (sum + temp) % MOD;

          return sum;
    }
};