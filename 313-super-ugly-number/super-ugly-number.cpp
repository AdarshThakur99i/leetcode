class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
           
            vector<int> temp(n+1,0);
            vector<int> pointer(primes.size(),1);
          
            
            temp[1]=1;  
           
            
               int i1=1;
          for(int i=2; i<=n; i++) { 
         long long mini=LLONG_MAX;
          
             for(int j=0; j<primes.size(); j++) {
                  if((long long)primes[j]*temp[pointer[j]]<mini) {
                  
                    mini=(long long)primes[j]*temp[pointer[j]];
                 
                  
             }
            
           
          } 
             temp[i]=mini;
             for(int j=0; j<primes.size(); j++) {
                if((long long)primes[j]*temp[pointer[j]]==mini) {
                    pointer[j]++;
                }
             }
             }
              return temp[n];
                }
};