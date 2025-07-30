class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
         for(int i=0; i<s.size(); i++) {
         mp[s[i]]++;
         }
       vector<vector<int>>bucket(s.size()+1);
       for(auto it: mp) {
        bucket[it.second].push_back(it.first);
       }

       string res="";
       for(int i=bucket.size()-1; i>=0; i--) {
           for(auto it: bucket[i]) {
            res+=string(i,it);
           }
       }
         return res;
    }
};