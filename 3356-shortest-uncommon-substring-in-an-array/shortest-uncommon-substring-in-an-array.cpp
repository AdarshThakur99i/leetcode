class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        unordered_map<string,int> mp;
        for(int i=0; i<arr.size(); i++) {string temp=arr[i];
            for(int j=0; j<arr[i].size(); j++) {
                   for(int k=j; k<arr[i].size(); k++) {
                         string sub=temp.substr(j,(k-j+1));
                         
                         mp[sub]++;
                   }
            }
        }
        vector<string> res(arr.size(),string(1,char(127)));
  for(int i=0; i<arr.size(); i++) {
     unordered_map<string,int> mp2;
    string temp=arr[i];
    for(int j=0; j<arr[i].size(); j++) {
                   for(int k=j; k<arr[i].size(); k++) {
                         string sub=temp.substr(j,(k-j+1));
                        mp2[sub]++;
                   }
    }
            for(int j=0; j<arr[i].size(); j++) {
                   for(int k=j; k<arr[i].size(); k++) {
                         string sub=temp.substr(j,(k-j+1));
                          if(mp[sub]==mp2[sub]) {
                            if(res[i]==string(1,char(127))) res[i]=sub;
                           else  if(sub.size()<res[i].size()) {
                                res[i]=sub;
                             }
                             else if(sub.size()==res[i].size()){
                                res[i]=min(res[i],sub);
                             }
                          }
                        
                   }
            }
            if(res[i]==string(1,char(127))) res[i]="";
        }
   return res;
    }
};