class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
          int cntone=0;
          string mini="1e9";
          int minlen=INT_MAX;
             for(int i=0; i<s.size(); i++) {
                    cntone=0;
                for(int j=i; j<s.size(); j++) {
                    if(s[j]=='1') {
                        cntone++;
                    }
                  if(cntone==k && (j-i+1)<minlen) {
                    string temp=s.substr(i,j-i+1);
                    mini=temp;
                    minlen=(j-i+1);
                  }
                  else if(cntone==k && (j-i+1)==minlen) {
                     string temp=s.substr(i,j-i+1);
                    mini=min(mini,temp);
                  }
                  if(cntone>k) break;
                }
             }
             return (mini=="1e9")?"":mini;
    }
};