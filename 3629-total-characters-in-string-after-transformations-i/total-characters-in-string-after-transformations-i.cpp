class Solution {
public:
    const int MOD = 1e9 + 7;

    int lengthAfterTransformations(string s, int t) {
        long long increase = 0;
        vector<int> mp(26, 0);

        // Step 1: Initial frequency count
        for (char ch : s) {
            mp[ch - 'a']++;
        }

        // Step 2: Perform t transformations
        for (int i = 0; i < t; ++i) {
            vector<int> temp(26, 0);

            for (int j = 0; j < 26; ++j) {
                int freq = mp[j];

                if (j == 25) { // If character is 'z'
                    temp[0] = (temp[0] + freq) % MOD; // 'a'
                    temp[1] = (temp[1] + freq) % MOD; // 'b'
                } else {
                    temp[j + 1] = (temp[j + 1] + freq) % MOD;
                }
            }

            mp = move(temp);
        }

        // Step 3: Total length after all transformations
        for (int count : mp) {
            increase = (increase + count) % MOD;
        }

        return static_cast<int>(increase);
    }
};
