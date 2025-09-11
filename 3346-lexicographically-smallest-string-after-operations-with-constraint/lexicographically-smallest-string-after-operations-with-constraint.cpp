class Solution {
public:
 string getSmallestString(string s, int k) {
       
             for(int i=0; i<s.size(); i++) {
                if(k<=0) break;
                    int idx=s[i]-'a';
                    int mini=min(idx,26-idx);
                    if(mini<=k) {
                       s[i]='a';
                        k-=mini;
                    }
                    else {
                        s[i]='a'+idx-k;
                        k=0;
                    } 
             }
         return s;
    }
};

//z z z z z z z z z z