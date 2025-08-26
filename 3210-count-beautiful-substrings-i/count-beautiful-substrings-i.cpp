class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int cnt=0;
        for(int i=0; i<s.size(); i++) {
            int vowel=0;
            int consonent=0;
            for(int j=i; j<s.size(); j++) {
                if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u') {
                    vowel++;
                }
                else {
                    consonent++;
                }
                if(vowel==consonent && ((vowel * consonent) % k) == 0) cnt++;
            }
        }
        return cnt;
    }
};