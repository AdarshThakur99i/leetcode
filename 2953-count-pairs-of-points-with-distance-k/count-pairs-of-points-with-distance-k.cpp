class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
              int ans=0;
              unordered_map<long long,int> mp;
              for(int i=0; i<coordinates.size(); i++) {
                int x=coordinates[i][0];
                int y=coordinates[i][1];
                  for(int j=0; j<=k; j++) {
                    int dx=j;
                    int dy=k-j;

                    int nx=dx^x;
                    int ny=dy^y;
                    long long key=((long long)nx<<20) | ny;
ans+=mp[key];
                    
                  }
                   long long key=((long long)x<<20) | y;
                   mp[key]++;                  
              }
               return ans;
    }
};