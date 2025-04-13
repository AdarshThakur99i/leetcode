class Solution {
public:

 long long solve(long long a ,long long b ) {
         if(b==0) return 1;
    long long half=solve(a,b/2)%MOD;

    long long res=(half*half)%MOD;

    if(b%2!=0) {
        res=(res*a)%MOD;
    }

    return res%MOD;
 }
const long long MOD=1e9+7;
    int countGoodNumbers(long long n) {
int count=0;
         if(n%2==0) {
            count=(solve(5,n/2)*solve(4,n/2))%MOD;
         }
         else {
            count=(solve(5,n/2+1)*solve(4,n/2))%MOD;
         }
      

        return count%MOD;
    }
};