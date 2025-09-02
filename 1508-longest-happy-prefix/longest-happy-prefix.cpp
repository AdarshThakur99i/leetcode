class Solution {
public:
     void createLSP(string &s,vector<int> &lsp) {
              
                 lsp[0]=0;
                 int len=0;
                 int i=1;
                 while(i<s.size()) {
                     if(s[i]==s[len]) {
                          len++;
                          lsp[i]=len;
                          i++;
                     }
                    
                     else {
                        if(len != 0) {
                          len=lsp[len-1];
                          
                     }
                     else {
                        lsp[i]=0;
                        i++;
                     } }
                 }  }
    string longestPrefix(string s) {
          vector<int> lsp(s.size(),0);
          createLSP(s,lsp);
         
      int maxi=0;
     
    maxi=lsp.back();
      string temp= s.substr(0,(maxi));
      return temp;  

    }
};

//lsp[i] = the length of the longest proper prefix of s[0..i] that is also a suffix of s[0..i].
//Because s[0..n-1] = the whole string.
//So lsp[n-1] = the length of the longest prefix of the whole string that is also a suffix