class Solution {
public:
    long long numOfSubsequences(string s) {
      vector<int> pref(s.size(),0);
      vector<int> suff(s.size(),0);
      for(int i=0; i<s.size(); i++) {
          if(i) pref[i]+=pref[i-1];
          if(s[i]=='L')  pref[i]+=1;
      }
      for(int i=s.size()-1; i>=0; i--) {
          if(i+1 < s.size()) suff[i]+=suff[i+1];
          if(s[i]=='T') suff[i]+=1;
      }
        long long ans=0;
        long long best=0;
        long long ansl=0;
        long long ansr=0;
        for(int i=0; i<s.size(); i++) {
            long long p=(i-1>=0) ? pref[i-1] : 0;
            long long suffi=(i+1<s.size()) ? suff[i+1]:0;
          if(s[i]=='C') {
            ans+=p*suffi;
            ansl+=((p+1)*suffi);
            ansr+=(p*(suffi+1));
          }
          //addc 
          p=pref[i];
          suffi=suff[i];
          best=max(best,p*suffi);
        }
        return max({ans+best,ansl,ansr});  
    }
};
