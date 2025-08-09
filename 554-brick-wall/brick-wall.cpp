class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
     unordered_map<int,int> mp;
         for(int i=0; i<wall.size(); i++) {
   long long sum=0;

      for(int j=0; j<wall[i].size()-1; j++) {
               sum+=wall[i][j];
               mp[sum]++;
      }
         }
         int maxi=INT_MIN;
         for(auto it: mp) {
            maxi=max(maxi,it.second);
         }
         if(maxi==INT_MIN) return wall.size();
         return wall.size()-maxi;
    }
};