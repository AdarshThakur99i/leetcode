class Solution {
public:
    string robotWithString(string s) {
       int i=0;
       string res="";
       string temp="";
     vector<char> minRight(s.size());
     minRight[s.size()-1]=s[s.size()-1];
     for(int i=s.size()-2; i>=0; i--) {
              minRight[i]=min(s[i],minRight[i+1]);
     }

     while(i<s.size()) {
        temp.push_back(s[i]);

        char mini= (i+1<s.size())? minRight[i+1]: s[i];
        while(!temp.empty() && temp.back()<=mini) {
            res+=temp.back();
            temp.pop_back();
        }

        i++;
     }
     while(!temp.empty()) {
        res+=temp.back();
        temp.pop_back();
     }

return res;
    }
};