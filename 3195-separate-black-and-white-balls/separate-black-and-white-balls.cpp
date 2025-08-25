class Solution {
public:
    long long minimumSteps(string s) {
       long long black=0;
     long long idx=s.size()-1;
long long cnt=0;
     int j=s.size()-1;
     while(j>=0) {
       if(s[j]=='1') {
        cnt+=(idx-j);
        idx=idx-1;
       }

        j--;
     }
       return cnt;
    }
};