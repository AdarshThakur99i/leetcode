class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26,0);
        for(int i=0; i<s.size(); i++){
            int idx=s[i]-'a';
             freq[idx]++;
         }

         int vowelmax=0;
         int consmax=0;
         for(int i=0; i<26; i++) {
            char c='a'+i;
             if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') {
                    vowelmax=max(vowelmax,freq[i]);
            }
            else {
                consmax=max(consmax,freq[i]);
            }
         }
         return  vowelmax+consmax;
    }
};