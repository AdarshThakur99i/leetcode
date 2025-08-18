class Solution {
public:
    bool check(string a,string b) {
        if(b.size()>a.size()) return false;
        int i=0;
        int j=0;
        while(i<a.size() && j<b.size()) {
if(a[i]==b[j] ) {
    j++;
}
  else if(a[i]=='z' && b[j]=='a' || (b[j]==a[i]+1)) {
    j++;
  }
      i++;

        }
        if(j==b.size()) return true;
        return false;
    }
    bool canMakeSubsequence(string str1, string str2) {
        
           
           return check(str1,str2);
    }
};