class Solution {
public:
   int bfs(unordered_map<int,vector<int>> &mp,int k,int start,int N) {
    queue<pair<int,int>> q;
         q.push({start,0});
         vector<bool> vis(N,false);
        
     vis[start]=true;
         int count=0;
         while(!q.empty()) {
            int x=q.front().first;
            int dis=q.front().second;
            q.pop();
            if(dis>k) {
                continue;
            }
            count++;
             
            for(auto it: mp[x]) {
                if(!vis[it]) {
                   vis[it]=true;
                    q.push({it,dis+1});
                }
            }
         }
         return count;
   }
   vector<int> res(vector<vector<int>> edges,int d) {

    unordered_map<int,vector<int>> mp;
    for(auto it:edges) {
        mp[it[0]].push_back(it[1]);
        mp[it[1]].push_back(it[0]);
    }


    vector<int> result(edges.size()+1,0);
    for(int i=0; i<result.size(); i++) {
        result[i]=bfs(mp,d,i,edges.size()+1);
    }

    return result;
   }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
      vector<int> res1=res(edges1,k);
      vector<int> res2=res(edges2,k-1);
      int maxi=*max_element(begin(res2),end(res2));
    
      for(int i=0; i<res1.size(); i++) {
     res1[i]+=maxi;
      }

      return res1;

    }
};