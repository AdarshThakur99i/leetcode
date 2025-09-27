class Solution {
public:
    string majorityFrequencyGroup(string s) {
        if(s=="") return "";
        map<int,vector<char>> mp;
        for(char i='a'; i<='z'; i++) {
int cnt=0;
            for(int j=0; j<s.size(); j++) {
             if(s[j]==i) {
                 cnt++;
             }
            }
            if(cnt != 0)  mp[cnt].push_back(i);
          
        }
     vector<char> res;
       int maxi=0;
        for(auto &it: mp) {
              if(it.second.size() >= maxi) {
                  maxi=it.second.size();
                  res=it.second;
              
              }
          
            
        }
string temp="";
       
        for(int i=0; i<res.size(); i++) {
            temp+=res[i];
        }
        return temp;
    }
};