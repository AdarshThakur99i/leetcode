class Solution {
public:
    int maxDistance(string s, int k) {
     int S=0;
     int n=0;
     int e=0;
     int w=0;
     int maxD=INT_MIN;
     for(int i=0; i<s.size(); i++) {
       if(s[i]=='S') {
        S++;
       }
       else if(s[i]=='N') {
        n++;
       }
       else if(s[i]=='E') {
        e++;
       }
       else {
        w++;
       }
 int dis=abs(e-w)+abs(n-S);
 int wasted=i+1 - dis;
 int extra=0;
 if(wasted!=0) {
    extra=min(2*k,wasted);
 }
 dis+=extra;
 maxD=max(maxD,dis);
     }
    
      return maxD;
    }
};