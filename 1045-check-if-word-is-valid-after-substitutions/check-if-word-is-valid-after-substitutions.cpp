class Solution {
public:
    bool isValid(string s) {
         string res="";
         for(int i=0; i<s.size(); i++) {
            if(i+1 < s.size() && !res.empty() && ((res.back()=='a' && s[i]=='b' && s[i+1]=='c'))) {
                        res.pop_back();
                        i++;
            } 
            else if ((res.size() >=2 && res[res.size()-1]=='b' && res[res.size()-2]=='a' && s[i]=='c')) {
                res.pop_back();
                res.pop_back();
               
            }
            else {
                res+=s[i];
            }
         }
         if(res.empty()) return true;
         return false; 
    }
};