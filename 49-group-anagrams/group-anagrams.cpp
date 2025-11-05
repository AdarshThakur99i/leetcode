class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<int>> mp;
        vector<string> x=strs;
            for(int i=0; i<strs.size(); i++) {
                sort(begin(x[i]),end(x[i]));
            }
         for(int i=0; i<x.size(); i++) {
            mp[x[i]].push_back(i);
         }
         int j=0;
     vector<vector<string>> ans;
     for(auto it: mp) {

        string temp=it.first;
        vector<string> groups;
       for(auto it: it.second) {
        groups.push_back(strs[it]);
       }
       ans.push_back(groups);
       
     }
     return ans;
    }
};