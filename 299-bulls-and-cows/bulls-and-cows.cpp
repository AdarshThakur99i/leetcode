class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls=0;
        int cows=0;
       
        unordered_map<char,int> mp;
       for(int i=0; i<secret.size(); i++) {
        if(secret[i]==guess[i]) {
              bulls++;
        }
        else {
         mp[secret[i]]++;
        }
       }
       for(int i=0; i<guess.size(); i++) {
        if(guess[i]!=secret[i]) {
            if(mp[guess[i]]) {
                cows++;
                mp[guess[i]]--;
            }
        }
       }
       
       
    string res= to_string(bulls) + 'A' + to_string(cows)+'B';

    return res;
    }
};