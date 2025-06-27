class Solution {
public:
long long maxi=LLONG_MIN;
    void check(int n,long long product,long long sum,int i,int k) {
        if(sum>n || i>n) return;
       if(sum==n && k>=2) {
           maxi=max(maxi,product);
           return;
       }
     
       check(n,product*i,sum+i,i,k+1);
   
       check(n,product,sum,i+1,k);
    }
    int integerBreak(int n) {
         check(n,1,0,1,0);
         return maxi;
    }
};