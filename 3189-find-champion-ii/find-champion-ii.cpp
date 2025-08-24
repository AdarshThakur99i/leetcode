class Solution {
public:
//     void dfs(unordered_map<int,vector<int>>& adj,int i,vector<int> &vis) {
//   vis[i]=1;
//         for(auto it: adj[i])  {
//             if(!vis[it]) {
//                 dfs(adj,it,vis);
//             }
//         }
//     }
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n,0);

    for(int i=0; i<edges.size(); i++) {
        indegree[edges[i][1]]++;
    }
int cnt=0;
int ans=-1;
    for(int i=0; i<indegree.size(); i++) {
        if(indegree[i]==0) {
            if(cnt>0) return -1;
            ans=i;
            cnt++;
        }
    }
//         unordered_map<int,vector<int>> adj;
//         for(auto it: edges ) {
//             adj[it[0]].push_back(it[1]);
//         }
           
// int cnt=0;   int ans=-1;
//            for(int i=0; i<n; i++) {
//          vector<int> vis(n,0); 
//             dfs(adj,i,vis);
         
//             bool ok=true;
//               for(int j=0; j<n; j++) {

//                 if(vis[j]!=1) {
//                     ok=false;
//                     break;
//                 }
//               }
//               if(ok==true) {
//                 if(cnt>0) return -1;
//                 ans=i;
//                 cnt++;
//               }

//            }
         return ans;

    }
};