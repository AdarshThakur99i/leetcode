class Solution {
public:
  void dfs(int node,int parent,vector<int> &inTime,vector<int>& outTime,vector<int>& Xortree,vector<int> &nums,unordered_map<int,vector<int>> &mp,int &timer) {
         Xortree[node]=nums[node];
         inTime[node]=timer;
         timer++;
         for(auto it: mp[node]) {
            if(it != parent) {
                dfs(it,node,inTime,outTime,Xortree,nums,mp,timer);
                Xortree[node]^=Xortree[it];
            }
         }
         outTime[node]=timer;
         timer++;
  }
int getXor(int xor1,int xor2,int xor3) {
    int maxi=max({xor1,xor2,xor3});
    int mini=min({xor1,xor2,xor3});
    return maxi-mini;
}
  bool isAncestor(int i,int j,vector<int> &inTime,vector<int>& outTime) {
         return (inTime[i]<inTime[j] && outTime[i]>outTime[j]);
  }
  int minimumScore(vector<int>& nums,vector<vector<int>> &edges) {        unordered_map<int,vector<int>> mp;
        for(auto &it: edges) {
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }
        int n=mp.size();
        vector<int> inTime(n,0);
        vector<int> outTime(n,0); 
        vector<int> Xortree(n,0);
        int timer=0;
        dfs(0,-1,inTime,outTime,Xortree,nums,mp,timer);

        int res=INT_MAX;
        for(int i=1; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int xor1=0;
                int xor2=0;
                int xor3=0;
                 if(isAncestor(i,j,inTime,outTime)) {
                     xor1=Xortree[j];
                     xor2=Xortree[i]^xor1;
                     xor3=Xortree[0]^xor1^xor2;

                 }
                 else  if(isAncestor(j,i,inTime,outTime)) {
                     xor1=Xortree[i];
                     xor2=Xortree[j]^xor1;
                     xor3=Xortree[0]^xor1^xor2;

                 }
                 else {
                    xor1=Xortree[i];
                    xor2=Xortree[j];
                    xor3=Xortree[0]^xor1^xor2;
                 }
                 res=min(res,getXor(xor1,xor2,xor3));
            }
        }

        return res;

    }
};