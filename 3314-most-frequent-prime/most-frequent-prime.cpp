    vector<int> primes;
 void seive() {
   
    long long n=1000000; primes.assign(n+1,1);
      primes[0]=0;
      primes[1]=0;
      for(int i=2; i*i<=(n); i++) {
        if(primes[i]==1) {
        for(int j=i*i; j<=n; j+=i) {
        primes[j]=0;
        }
      }
      }
    }


class Solution {
public:
long long maxnumber;
vector<long long> mp;
   
    void dfs(vector<vector<int>>& mat,int i,int j,int dir,long long val) {
        long long newval = val * 10 + mat[i][j];
        if(newval>maxnumber) return;
         int delRow[]={1,1,0,-1,-1,-1,0,1};
         int delCol[]={0,1,1,1,0,-1,-1,-1};
       
        //    long long newval=val*10 + mat[i][j];
           if(newval >= 10 && newval < primes.size() && primes[newval]==1) {
            if(newval<mp.size())   mp[newval]++;
         
           }
           
           if(dir==-1) {
                for(int k=0; k<8; k++) {
                    int newRow=delRow[k]+i;
                    int newCol=delCol[k]+j;
                    if(newRow<mat.size() && newCol<mat[0].size() && newRow>=0 && newCol >=0) {
                        dfs(mat,newRow,newCol,k,newval);
                    }
                }

           }
           else {
               int newRow=delRow[dir]+i;
            int newCol=delCol[dir]+j;
             if(newRow<mat.size() && newCol<mat[0].size() && newRow>=0 && newCol >=0) {
         
            dfs(mat,newRow,newCol,dir,newval);}
           }

    }
    int mostFrequentPrime(vector<vector<int>>& mat) {
        if(primes.empty()) seive();
        int maxlen=max(mat.size(),mat[0].size());
       maxnumber=pow(10,maxlen)-1;
     
        mp.assign(maxnumber+2,0);
        
         for(int i=0; i<mat.size(); i++) {
            for(int j=0; j<mat[0].size(); j++) {
               
                dfs(mat,i,j,-1,0);
            }
         }
         int maxi=INT_MIN;
         
        
      int maxFreq = 0;
        int ans = -1;
        for (int i = 10; i <= maxnumber; i++) {
            if (mp[i] > maxFreq && primes[i]==1) {
                maxFreq = mp[i];
                ans = i;
            } else if (mp[i] !=0 && mp[i] == maxFreq && i > ans && primes[i]==1 ) {
                ans = i;
            }
        }
  
return ans;
    }
};

//999999999