class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& path) {
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> ans;
  
        for(int i=0; i<path.size(); i++) {
            string x=path[i];
            
            int j=0; string temp="";
            while(j < path[i].size()) {
               string temp2="";string num="";
                if(j==0) {
                 while(j<x.size() && x[j]!=' ') {
                    temp+=x[j];
                    j++;
                 }}
                 else {
                    
                    while(j<x.size() && x[j]!='.') {
                        num+=x[j];
                      j++;
                    }
                    j+=4;
                 while(j<x.size() && x[j]!=' ') {
                    if(x[j]=='(' || x[j]==')') {
                        j++;
                        continue;
                    }
                       temp2+=x[j];
                       j++;
                 }
                 }
                 if(temp2 !="") {
                 mp[temp2].push_back(temp+'/'+num+".txt");}
               
                j++;
                         }    
        }

        for(auto it : mp) {
            if(it.second.size()>1) ans.push_back(it.second);
            
           
        
           
        }
        return ans;
          
    }
};