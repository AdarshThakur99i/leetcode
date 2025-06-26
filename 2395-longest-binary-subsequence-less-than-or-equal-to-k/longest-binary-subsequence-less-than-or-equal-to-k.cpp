class Solution {
public:

    int longestSubsequence(string s, int k) {
       int len=0;
       int num=1;
        for(int i=s.size()-1; i>=0; i--) {
            if(s[i]=='0') {
                len++;
                 
            }
            else {
                if(1*num<=k) {
                    len++;
                    k=k-num;
                }
            }
            if(num<=k) {
                num*=2;
            }
        }
        return len;

        

        
    }
};