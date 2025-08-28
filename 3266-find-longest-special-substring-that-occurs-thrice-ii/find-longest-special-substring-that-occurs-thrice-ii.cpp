class Solution {
public:
    int maximumLength(string s) {
        vector<vector<int>> count(26);
       for(int i=0; i<s.size(); i++) {
          int j=i;
       while(j+1 < s.size() && s[j] == s[j+1]) j++;
         int idx=s[i]-'a';
         int len=j-i+1;
         if(count[idx].size()<len+1) {
            count[idx].resize(len+1);
         }

         for(int k=1; k<=len; k++) {
                 count[idx][k]+=len-k+1;
         }
         i=j;

       }
          int maxi=-1;
       for(int i=0; i<26; i++) {
            for(int j=0; j<count[i].size(); j++) {
                if(count[i][j] >=3) {
                    maxi=max(maxi,j);
                }
            }
       }
       return (maxi==-1) ? -1:maxi;
    }
};