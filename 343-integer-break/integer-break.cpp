class Solution {
public:
    int check(int n,int i,int k) {
         if(n==0 && k>=2) {
           return 1;
          
       }
        if(n<0 || i>n) return 0;
      
     
      int take= check(n-i,i,k+1);
   if(take>0) {
    take*=i;
   }
     int not_take=check(n,i+1,k);
     return max(take,not_take);
    }
    int integerBreak(int n) {
        return check(n,1,0);
      
    }
};