class Solution {
public: 
    bool isPowerOfThree(int n) {
        if(n<=0 ) return false;
        double x=n;
        while(n%3==0) {
           n= n/3;
        }
        return (n==1);
    }
};