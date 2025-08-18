class Solution {
public:
    bool checkStrings(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        vector<int> freq1even(26);
        vector<int> freq1odd(26);
         vector<int> freq2even(26);
        vector<int> freq2odd(26);
        for(int i=0; i<s1.size(); i++) {

            if(i%2==0) {
                freq1even[s1[i]-'a']++;
                freq2even[s2[i]-'a']++;
            }
            else {
                 freq1odd[s1[i]-'a']++;
                freq2odd[s2[i]-'a']++;
            }
        }
        return (freq1even==freq2even) && (freq1odd==freq2odd);
    }
};