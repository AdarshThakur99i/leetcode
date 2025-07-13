class Solution {
public:

    int findNthDigit(int n) {
        int cnt=0;
       
       long long base=9;
       long long digit=1;
       while(n-(base*digit) > 0) {
        n-=(base*digit);
        base*=10;
        digit++;
       }

       int idx=n%digit;
       if(idx==0) {
        idx=digit;
       }
       long long num=1;
       for(int i=1; i<digit; i++) {
        num*=10;
       }
       num+=(idx==digit) ? n/digit -1 : n/digit;
         for(int i=idx; i<digit; i++) {
            num/=10;
         }

         return num%10;
    }
};