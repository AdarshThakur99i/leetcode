class Solution {
public:
vector<long long> bits;


    void check(long long k,int x,long long num) {
               if(num==0) return;
               if(num==1) {
                bits[0]+=1;
                return;
               }
               if(num==2) {
                bits[0]+=1;
                bits[1]+=1;
                return;
               }

         long long bitlen=log2(num);
         long long nearestpower=(1LL << bitlen);
         bits[bitlen] += num-nearestpower+1;
         for(long long i=0; i<bitlen; i++) {
            bits[i]+=nearestpower/2;
         }
        num=num-nearestpower;
         check(k,x,num);
    }
    long long findMaximumNumber(long long k, int x) {
        

        long long l=0;
        long long r=1e15;
        long long result=0;
        while(l<=r) {
            long long mid=(l+(r-l)/2);
            bits=vector<long long>(65,0);
            check(k,x,mid);
            long long total=0;
            for(long long i=0; i<(log2(mid)+1); i++) {
                if((i+1)%x ==0) {
                    total+=bits[i];
                }
            }
            if(total <=k) {
                result=mid;
                l=mid+1;
            }
            else {
                r=mid-1;
            }
        }
     return result;
    }
};