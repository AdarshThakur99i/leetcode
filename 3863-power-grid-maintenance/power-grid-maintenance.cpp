class Solution {
public:
    vector<int> parent;
    vector<bool> isOnline;
    vector<set<int>> online;
    vector<int> rank;

   int find(int x) {

         if(parent[x]!=x) {
              parent[x]=find(parent[x]);
         }
         return parent[x];
   }

   void unite(int a,int b) {
    int p1=find(a);
    int p2=find(b);
    if(p1==p2) return;

    if(rank[p1]>rank[p2]) {
        parent[p2]=p1;
        online[p1].insert(online[p2].begin(),online[p2].end()); 
        online[p2].clear();
    }
    else if(rank[p2]>rank[p1]) {
         parent[p1]=p2;
        online[p2].insert(online[p1].begin(),online[p1].end()); 
        online[p1].clear();
    }
    else {
        rank[p1]++;
        parent[p2]=p1;
        online[p1].insert(online[p2].begin(),online[p2].end()); 
        online[p2].clear();
    }
   }


    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
           parent.resize(c+1);
           isOnline.assign(c+1,true);
           rank.assign(c+1,0);
           online.resize(c+1);
           for(int i=1; i<=c; i++) {
            parent[i]=i;
            online[i].insert(i);
           }
           for(auto it: connections) {
            unite(it[0],it[1]);
           }
        vector<int> ans;
        for(int i=0; i<queries.size(); i++) {
            if(queries[i][0]==1) {
                if(isOnline[queries[i][1]]) {
                    ans.push_back(queries[i][1]);
           
                }
                else {
                    int root=find(queries[i][1]);
                if(online[root].empty()) {
                    ans.push_back(-1);
                } 
                else {
                    ans.push_back(*online[root].begin());
                }   
                }
                
            }
            else {
                if(isOnline[queries[i][1]]) {
                isOnline[queries[i][1]]=false;
                int root=find(queries[i][1]);
                online[root].erase(queries[i][1]);
            }}
        }
           return ans;
    }
};