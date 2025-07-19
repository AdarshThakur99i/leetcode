class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
     sort(begin(folder),end(folder));
     unordered_set<string> st;
     vector<string> ans;
     for(int i=0; i<folder.size(); i++) {
string res="";
bool check=true;
for(int j=0; j<folder[i].size(); j++) {
    if(folder[i][j]=='/'){
        if(!res.empty()) {
            if(st.find(res)!=st.end()) {
                check=false;
                break;

            }
        }}
    res+=folder[i][j];
    }
    

if(check==true) {
    ans.push_back(res);
    st.insert(res);
}
     }

return ans;
     }
        
    
};