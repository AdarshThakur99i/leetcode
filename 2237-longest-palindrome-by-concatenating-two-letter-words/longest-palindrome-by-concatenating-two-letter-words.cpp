class Solution {
public:
int maxi=INT_MIN;
    int longestPalindrome(vector<string>& words) {
       unordered_map<string,int> mp;
       int sum=0;
       for(int i=0; i<words.size(); i++) {
        string temp=words[i];
        reverse(begin(temp),end(temp));
        if(mp[temp]>0) {
            sum+=4;
            mp[temp]--;
            continue;
        }
        
        mp[words[i]]++;
       }

          for(auto it: mp) {
            string word=it.first;
            int cnt=it.second;
            if(word[0]==word[1] && cnt>0) {
                 sum+=2;
                 break;
            }
          }

        return sum;
    }
};