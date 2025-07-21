class Solution {
public:
    string makeFancyString(string s) {
        string res="";
       
        int cnt=0;
        for(int i=0; i<s.size(); i++) {
            if(!res.empty() && s[i]==res.back() && cnt==1) {
                continue;
            }
   if(!res.empty() && s[i]==res.back()) {
       cnt++;
   }
   else {
    cnt=0;
   }
       res+=s[i];

        }
           
return res;
    }
        
    
};