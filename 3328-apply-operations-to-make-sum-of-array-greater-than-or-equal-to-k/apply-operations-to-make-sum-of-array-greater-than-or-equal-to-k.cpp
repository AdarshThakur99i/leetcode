class Solution {
public:
    // int check(int k,int sum ) {
    //       if(sum>=k) return 0;
    //     int inc_one=1+check(k,sum+1);
    //     int inc_twice=1+check(k,sum+sum);

    //     return min(inc_one,inc_twice);
    // }

    int minOperations(int k) {
        if(k==1) return 0;
         int m=sqrt(k);

         int sum= (m-1)+ (k-1)/m;
         return sum;
    }
};