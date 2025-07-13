class Solution {
public:
    string removeKdigits(string num, int k) {
           string res="";
           for(int i=0; i<num.size(); i++) {
                while(!res.empty() && res.back() > (num[i]) && k>0) {
                    res.pop_back();
                    k--;
                }
                res.push_back(num[i]);  }
                while(k>0 && !res.empty()) {
       res.pop_back();
       k--;
                }
                int i=0;
                while(i<res.size() && res[i]=='0') {
                    i++;
                }
                res=res.substr(i);
                return res.empty() ? "0" : res;

           
    }
};