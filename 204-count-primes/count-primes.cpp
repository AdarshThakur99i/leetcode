class Solution {
public:

  int primes(int n) {
    vector<int> temp(n,0); 
temp[0]=1;
temp[1]=1;

    for(int i=2; i<sqrt(n); i++) {
    
        for(int j=i*i; j<n; j+=i) {
            temp[j]=1;

        
    }}

   int count=0;
   for(int i=0; i<temp.size(); i++) {
    if(temp[i]==0) count++;



   }
   return count;
  }
    int countPrimes(int n) {
        if(n<=1) return 0;
        

        return primes(n);
        
    }
};