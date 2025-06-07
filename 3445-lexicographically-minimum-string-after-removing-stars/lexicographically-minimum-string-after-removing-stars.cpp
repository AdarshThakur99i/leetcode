class Solution {
public:

  struct compare {
    bool operator()(const pair<char,int> &a,const pair<char,int> &b) const {
        if(a.first==b.first) {
            return a.second>b.second;
        }

        return a.first<b.first;
    }
  };
    string clearStars(string s) {
        
        set<pair<char,int>,compare> st;
        vector<int> deletee(s.size(),0);
       
        int k=0;
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='*') {
                auto x=*st.begin();
                 int idx=x.second;
                deletee[idx]=1;
                deletee[i]=1;
                 st.erase(x);
              
               continue;
            }
             st.insert({s[i],i});
        }
       string res="";
        for(int i=0; i<s.size(); i++) {
            if(deletee[i]==0) {
                res+=s[i];
            }
        }
       
   return res;
    }
};