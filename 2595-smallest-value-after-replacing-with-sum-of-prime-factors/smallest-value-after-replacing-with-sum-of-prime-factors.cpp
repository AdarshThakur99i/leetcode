class Solution {
public:
     
     int check(int n) {
int sum=0;
        while(n%2==0) {
          sum+=2;
          n=n/2;
        }
        for(int i=3; i*i<=n; i+=2) {
    while(n%i ==0) {
        sum+=i;
        n=n/i;
    }
            
        }
        if(n>1) sum+=n;
        return sum;
     }
    int smallestValue(int n) {
          
          while(true) {
         int sum=check(n);
         if(sum==n) return n;
         n=sum;
          }
          return n;
    }
};