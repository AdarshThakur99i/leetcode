class Solution {
public:
    bool isPowerOfFour(int n) {
          if(n<=0) return false;
          int temp=1;
        if((n&(n-1))==0) {
             while(temp<n) {
                temp=temp*4;
             }
             if(temp==n) return true;
             else return false;
        }
        return false;
    }
};