class Solution {
public:
    void build(string &word,vector<int> &lsp) {
               
               int i=1;
               lsp[0]=0;
               int len=0;
               while(i<word.size()) {

                if(word[i]==word[len]) {
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
                    }
                }
               }

               
    }
    int minimumTimeToInitialState(string word, int k) {
           vector<int> lsp(word.size(),0);
           build(word,lsp);
int n=word.size();
           int len=lsp.back();
          
           while(len>0 && ((n-len)%k) !=0) {
            len=lsp[len-1];
           }
           if((n-len)%k ==0) {
            return (n-len)/k;
           }
 
           return  ceil(n/(double)k);


    }
};