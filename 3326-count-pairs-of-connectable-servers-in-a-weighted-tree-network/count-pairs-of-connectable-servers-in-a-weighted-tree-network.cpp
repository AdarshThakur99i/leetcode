class Solution {
public:
int signal;
     int check(unordered_map<int,vector<pair<int,int>>> &mp,int i,int currdis,int parent) {
        int cnt=0;
        if(currdis % signal ==0) cnt++;
     
          for(auto it: mp[i]) {
          
            int dist=it.second;
            int node=it.first;
            if(node != parent) {
           cnt+= check(mp,node,dist+currdis,i);
            }
               
          }

          return cnt;
     }
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
              unordered_map<int,vector<pair<int,int>>> mp;
              for(auto it : edges) {
                mp[it[0]].push_back({it[1],it[2]});
                mp[it[1]].push_back({it[0],it[2]});
              }  
              signal=signalSpeed;
              
vector<int> res;
              for(int i=0; i<(edges.size()+1); i++) {
                     vector<int> count;
                     for(auto it: mp[i]) {
                        count.push_back(check(mp,it.first,it.second,i));
                     }
                      int sum=accumulate(begin(count),end(count),0);
                      long long total=0;
                     for(int j=0; j<count.size(); j++) {
                         total+= (count[j]*(sum-count[j]));
                     }
                   res.push_back(total/2);

              }
          return res;
    }
};