class Solution {
public:
     long long check(unordered_map<int,vector<int>> &mp,int par,vector<int> &values,int i) {
                  

                 
long long sum=0;   
                  for(auto it: mp[i]) {
                    if(it != par) {
                    sum+=check(mp,i,values,it);
                    }
                  }
                  long long x=values[i];
                  if(sum==0) return values[i];
                  
                  return min(sum,x);

     }
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
          unordered_map<int,vector<int>> mp;
          for(int i=0; i<edges.size(); i++) {
                 mp[edges[i][0]].push_back(edges[i][1]);
                 mp[edges[i][1]].push_back(edges[i][0]);
          }
          long long sum=accumulate(begin(values),end(values),0LL);
        long long removed=check(mp,-1,values,0);
             return sum-removed;      
    }
};