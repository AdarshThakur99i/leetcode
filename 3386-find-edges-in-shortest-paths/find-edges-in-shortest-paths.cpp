class Solution {
public:
    void calculate(int src,vector<int> &dis,unordered_map<int,vector<pair<int,int>>> &mp) {
            
          priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
dis[src]=0;
            q.push({0,src});
            while(!q.empty()) {
                    auto x=q.top();
                    q.pop();
                    int i=x.second;
                    int dist=x.first;
                    for(auto it: mp[i]) {
                        int wt=it.first;
                        int newi=it.second;
                        if(dist+wt < dis[newi]) {
                            dis[newi]= dist+wt;
                            q.push({dis[newi],newi});
                        }
                    }

            }


    }
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<pair<int,int>>> mp;
        
        for(auto it: edges) {
            mp[it[0]].push_back({it[2],it[1]});
            mp[it[1]].push_back({it[2], it[0]});
        }
        vector<int> FromSrc(n,INT_MAX);
        vector<int> FromEnd(n,INT_MAX);
        calculate(0,FromSrc,mp);
        calculate(n-1,FromEnd,mp);
vector<bool> result(edges.size(),false);
       for(int i=0; i<edges.size(); i++) {
        int u=edges[i][0];
        int v=edges[i][1];
        int w=edges[i][2];

       if (FromSrc[u] != INT_MAX && FromEnd[v] != INT_MAX &&
    FromSrc[u] + w + FromEnd[v] == FromSrc[n-1]) {
    result[i] = true;
}
        if(FromSrc[u] != INT_MAX && FromEnd[v] != INT_MAX &&FromSrc[v]+FromEnd[u]+w ==FromSrc[n-1])  {
            result[i]=true;
        }
       }

       return result;
    }
};