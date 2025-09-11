class Solution {
public:
    string sortVowels(string s) {
        string x="";
        for(int i=0; i<s.size(); i++ ) {
            if(s[i]=='a'|| s[i]=='e'|| s[i]=='i'|| s[i]=='o'|| s[i]=='u'||s[i]=='A'||s[i]=='E'|| s[i]=='I'|| s[i]=='O'|| s[i]=='U')    x+=s[i];
        }

        sort(begin(x),end(x));
        int idx=0;
         for(int i=0; i<s.size(); i++ ) {
            if(s[i]=='a'||s[i]=='e'|| s[i]=='i'|| s[i]=='o'|| s[i]=='u'||s[i]=='A'||s[i]=='E'|| s[i]=='I'|| s[i]=='O'|| s[i]=='U')    s[i]=x[idx++];
        }

        return s;
    }
};