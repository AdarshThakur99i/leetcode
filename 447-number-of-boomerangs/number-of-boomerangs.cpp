class Solution {
public:
  void check(vector<vector<int>>& points,int i,unordered_map<int,int> &mp,int x,int y,int curr) {
     
        if(i>=points.size()) return;
     int dis=pow((x-points[i][0]),2)+pow((y-points[i][1]),2);
         mp[dis]++;
            check(points,i+1,mp,x,y,curr);
  }
    int numberOfBoomerangs(vector<vector<int>>& points) {
           int ans=0;
          for(int i=0; i<points.size(); i++) {
        unordered_map<int,int> mp;     check(points,0,mp,points[i][0],points[i][1],i);
            for(auto it:mp) {
                // if(it.first==0) continue;
                int x=it.second;
                if(x>1) {
                 ans+= x*(x-1);
                }
            }
        
          }
          return ans;
    }
};

 
// x,y 4 4 4  
//n(n-1)/2 15
//3*