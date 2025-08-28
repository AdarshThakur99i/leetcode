class Solution {
public:
   void Floywashal(vector<vector<long long>> &adj,vector<char>& original,vector<char>& changed,vector<int>& cost) {

           for(int i=0; i<cost.size(); i++) {
            int a = original[i]-'a';
            int b = changed[i]-'a';
             adj[a][b]=min((long long)cost[i],adj[a][b]);
           }
           for(int k=0; k<26; k++) {
            for(int i=0; i<26; i++) {
                for(int j=0; j<26; j++) {
                    adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
                }
            }
           }  
           
   }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
         
          vector<vector<long long>> adj(26,vector<long long>(26,INT_MAX));

          Floywashal(adj,original,changed,cost);
   long long cnt=0;
          for(int i=0; i<source.size(); i++) {
            if(source[i]!=target[i]) {
                int a=source[i]-'a';
                int b=target[i]-'a';
              if(adj[a][b]==INT_MAX) return -1;
              cnt+=adj[a][b];
            }
          }

          return cnt;
    }
};