class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
          int idx=0;
          int i=0;
          vector<int> idxi;
          vector<int> idxj;
          while(i<s.size()) {
            if(s[i]==a[idx]) {
                int k=i;
                while(i<s.size() && idx<a.size() && s[i]==a[idx]) {
                      

                      i++;
                      idx++;
                }
                if(idx==a.size()) {
                        idxi.push_back(k);
                    
                       
                }
                
                 idx=0;
                 i=k;
            }
            i++;
           
          }
          i=0;
          idx=0;
             while(i<s.size()) {
            if(s[i]==b[idx]) {
                int k=i;
                while(i<s.size() && idx<b.size() && s[i]==b[idx]) {
                      i++;
                      idx++;
                }
                if(idx==b.size()) {
                        idxj.push_back(k);
                       
                }
                
                 idx=0;
                 i=k;
            }
            i++;
          }
          vector<int> ans;
          sort(begin(idxi),end(idxi));
          sort(begin(idxj),end(idxj));
            for(int i=0; i<idxi.size(); i++) {
                auto x=lower_bound(begin(idxj),end(idxj),(idxi[i]-k));
                
                if(x!=idxj.end() && *(x) <= idxi[i]+k) ans.push_back(idxi[i]);
            }
         
       return ans;
    }
};