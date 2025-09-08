class Solution {
public:
    string minimizeStringValue(string s) {
        vector<pair<char,int>> temp;
          unordered_map<char,int> mp;
           for(int i=0; i<s.size(); i++) {
            mp[s[i]]++;
           }
          for(int i=0; i<s.size(); i++) {

            if(s[i]!='?') {
     continue;
            }

            else {
                bool ok=false;
                for(int j='a'; j<='z'; j++) {
                     if(!mp.count(j)) {
                         
                          mp[j]++;
                          temp.push_back({j,i});
                          ok=true;
                          break;
                     }
                }
                if(ok==false) {
                    char ch='a';
                    int maxi=INT_MAX;
                    for(char it='a'; it<='z'; it++) {
                        int freq=mp[it];
                     if (freq < maxi || (freq == maxi && it < ch)) {
    maxi = freq;
    ch = it;
}
                    } 
                    temp.push_back({ch,i});
                   
                    mp[ch]++;

                }
            }
          }
          sort(begin(temp),end(temp),[](auto & a,auto &b) {
                      return a.first<b.first;
          });
int idx=0;
          for(int i=0; i<s.size(); i++) {
             if(s[i]=='?') {
                s[i]=temp[idx++].first;
             }
          }
          return s;
    }
};