class Solution {
public:
  
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
            sort(begin(people),end(people),[](const vector<int>& a,const vector<int> &b) {
                   if(a[0]==b[0]) return a[1]<b[1];
                   return a[0]>b[0];
            });
            vector<vector<int>> res;
            for(auto it: people) {
                res.insert(res.begin()+it[1],it);
            }  

            return res;
    }
};