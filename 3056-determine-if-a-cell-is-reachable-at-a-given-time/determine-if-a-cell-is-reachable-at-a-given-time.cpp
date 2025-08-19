class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
       
        int y= abs(fy-sy);
      
        int x=abs(fx-sx);
      
        int sum=max(x,y);
        if(sum==0) return t!=1;

        return (sum<=t);
         
    }
};