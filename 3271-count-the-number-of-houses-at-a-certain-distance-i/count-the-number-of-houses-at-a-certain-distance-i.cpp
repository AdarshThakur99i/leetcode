class Solution {
public:
   int N;
        vector<int> bfs(int n,unordered_map<int,vector<int>>& mp,int i) {

                vector<int> dist(n+1,INT_MAX);
                dist[i]=0;
                queue<int> q;
                q.push(i);
                while(!q.empty()) {
                    int x=q.front();
                    q.pop();
                    for(auto it: mp[x]) {
                        if(it != x && dist[it]==INT_MAX) {
                              dist[it]=dist[x]+1;
                              q.push(it);
                        }
                    }
                }

                return dist;
        }
    vector<int> countOfPairs(int n, int x, int y) {
           unordered_map<int,vector<int>> mp;

           for(int i=1; i<=n; i++) {
            if(i+1 <= n) {
            mp[i].push_back(i+1);
            mp[i+1].push_back(i);
            }
           }
           mp[x].push_back(y);
           mp[y].push_back(x);
vector<int> res(n,0);
         for(int i=1; i<=n; i++) {
            vector<int> dist=bfs(n,mp,i);
            for(int v=1; v<=n; v++) {
                if( i!= v && dist[v]!=INT_MAX)    res[dist[v]-1]++;
             
            }
         }
               
        return res;
    }
};