class Solution {
public:
int cap1;
int cap2;
   bool check(int target,int x,int y,set<pair<int,int>> &vis) {
           if(x+y==target) {
            return true;
           }
           if(vis.count({x,y})) return false;
           vis.insert({x,y});
           return check(target,x,cap2,vis) || check(target,cap1,y,vis) || check(target,0,y,vis) || check(target,x,0,vis) || check(target,x-min(x,cap2-y),y+min(x,cap2-y),vis) ||  check(target,x+min(y,cap2-x),y-min(y,cap2-x),vis);
   }
    bool canMeasureWater(int x, int y, int target) {
            set<pair<int,int>> vis;
             cap1=x;
             cap2=y;

             return check(target,0,0,vis);
             
    }
};