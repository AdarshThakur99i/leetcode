class Solution {
public:
    void calculateLPS(string pattern,vector<int>& lps) {
         int len=0;
         int i=0;
         lps[i]=0;
         i=1;

         while(i<pattern.size()) {
              if(pattern[i]==pattern[len]) {
                 len++;
                 lps[i]=len;
                 i++;
              }
              else {
                if(len != 0) {
                    len=lps[len-1];

                }
                else {
                    lps[i]=0;
                   
                    i++;
                }
              }
         }
           }
    string shortestPalindrome(string s) {
        int i=0; 
        int j=s.size()-1;
    string temp=s;
    reverse(begin(temp),end(temp));
    string x=s+'-'+temp;
    vector<int> lps(x.size(),0);
    calculateLPS(x,lps);
    int ans=lps.back();
    string temp2=temp.substr(0,s.size()-ans);
    return temp2+s;     
    }
};