class Solution {
public:
     double dfs(string a ,string b , string i,map<string,vector<pair<string,double>>> &adj,double product,unordered_set<string> &vis) {
             vis.insert(i);
   if(i==b) {
                   
            return product;
                }
             for(auto it: adj[i]) {
                string curr=it.first;
                double wt=it.second;
               
                if(vis.find(curr)==vis.end()) {
                double res= dfs(a,b,curr,adj,product*wt,vis);
                if(res!=-1) {
                    return res;
                }
                }  
             
             }  vis.erase(i);
          
          return -1;
     }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)   {
          map<string,vector<pair<string,double>>> adj;
    int val=0;
    for(auto it: equations) {
        adj[it[0]].push_back({it[1],values[val]});
        adj[it[1]].push_back({it[0],(1/values[val])});
        val++;
    }
   
   unordered_set<string> vis;
   vector<double> ans;
    for(int i=0; i<queries.size(); i++) {
              string a =queries[i][0];
              string b=queries[i][1];
             if(!adj.count(a) || !adj.count(b)) {
                ans.push_back(-1);
                continue;
             }

              double res=dfs(a,b,a,adj,1,vis);
             
              ans.push_back(res); 
              
              vis.clear();

        
       
    }
    return ans;
    }
};