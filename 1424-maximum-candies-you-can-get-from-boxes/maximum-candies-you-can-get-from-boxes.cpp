class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
       
        int cnt=0;
        unordered_map<int,int> mp;
       queue<int> q;
       vector<int> vis(candies.size(),0);
       unordered_set<int> foundBoxes;
      for(int i=0; i<initialBoxes.size(); i++) {
        foundBoxes.insert(initialBoxes[i]);
        if(status[initialBoxes[i]]==1) {
            q.push(initialBoxes[i]);
            vis[initialBoxes[i]]=1;
            
            }
      }
       while(!q.empty()) {
        int i=q.front();
        q.pop();
    cnt+=candies[i];
        for(int j=0; j<containedBoxes[i].size(); j++) {
            foundBoxes.insert(containedBoxes[i][j]);
            if((status[containedBoxes[i][j]]==1 || mp[containedBoxes[i][j]]>0) && vis[containedBoxes[i][j]]==0) {
                q.push(containedBoxes[i][j]);
                vis[containedBoxes[i][j]]=1;
              
            }
        }

        for(auto it: keys[i]) {
            mp[it]++;
           status[it]=1;
           if(foundBoxes.count(it) && vis[it]==0) {
            q.push(it);
            vis[it]=1;
            
           }
        }
           
        }
      return cnt;
     }   
};