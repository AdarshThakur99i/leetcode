class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> original;
        for(int i=0; i<strs.size(); i++) {
            original.push_back(strs[i]);
        }
          for(auto &it:strs) {
            sort(begin(it),end(it));
          }
          vector<bool> used(strs.size(),false);
vector<vector<string>> ans;
for(int i=0; i<strs.size(); i++) {
    if(used[i]) continue;

    vector<string> temp;

    for(int j=i; j<strs.size(); j++) {
        if(!used[j] && strs[i]==strs[j]) {
            used[j]=true;
            temp.push_back(original[j]);
             
        }
    }
    ans.push_back(temp);
}

return ans;

    }
};