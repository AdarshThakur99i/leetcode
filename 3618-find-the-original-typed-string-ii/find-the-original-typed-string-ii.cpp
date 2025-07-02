class Solution {
public:
const int MOD=1e9+7;

    int possibleStringCount(string word, int k) {
          if(k > word.length())
            return 0;
        int len=word.size();
      vector<int> freq;
      int count=1;
       for(int i=1; i<word.size(); i++) {
           if (word[i]==word[i-1]) {
            count++;

           }
           else {
            freq.push_back(count);
            count=1;
           }
       }
       freq.push_back(count);
       long long p=1;
       for(auto &f: freq) {
        p=(p*f)%MOD;
       }
       if(freq.size()>=k) {
        return p;
       }
       int n=freq.size();
      vector<vector<int>> t(n+1, vector<int>(k+1, 0));

        for(int count = k-1; count >= 0; count--) {
            t[n][count] = 1;
        }

        for(int i = n-1; i >= 0; i--) {
              vector<int> prefix(k+1, 0);
            for(int h = 1; h <= k; h++) {
                prefix[h] = (prefix[h-1] + t[i+1][h-1]) % MOD;
            }

            for(int count = k-1; count >= 0; count--) {
                
                int l = count + 1;
                int r = count + freq[i];

                if(r+1 > k) {
                    r = k-1;
                }

                if(l <= r) {
                    t[i][count] = (prefix[r+1] - prefix[l] + MOD) % MOD;
                }
                
            }
        }

        long long invalidCount = t[0][0];
      return (p-invalidCount+MOD)%MOD;
      
    }   
};