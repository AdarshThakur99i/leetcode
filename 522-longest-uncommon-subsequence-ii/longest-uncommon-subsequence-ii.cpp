class Solution {
public:
 bool subseq(vector<string>& strs,string &s1 ,string &s2) {

    int i=0;
    int j=0;
    while(j<s2.size() && i<s1.size()) {
        if(s2[j]==s1[i]) {
         i++;
    }
    j++;}

   if(i==s1.size()) return true;
   return false;

 }
    int findLUSlength(vector<string>& strs) {
        int maxi=-1;
        for(int i=0; i<strs.size(); i++) {
            bool check=false;
            for(int j=0; j<strs.size(); j++) {
                if(i==j) continue;
              if(subseq(strs,strs[i],strs[j])) {
                     check=true;
                     break;
              }
            }
            if(check==false) {
                int x=strs[i].size();
                maxi=max(maxi,x);
            }
        }
        return maxi;
    }
};