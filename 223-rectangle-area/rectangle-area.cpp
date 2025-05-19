class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int xx=0;
        int yy=0;
   
    int xx1=max(ax1,bx1);
    int  xx2=min(ax2,bx2);
    int yy1=max(ay1,by1);
    int yy2=min(ay2,by2);

    int l=xx2-xx1;
    int b=yy2-yy1;
 
   int a1=(ax2-ax1) * (ay2-ay1);
   int a2=(bx2-bx1)*(by2-by1);
if(xx2<=xx1 || yy2<=yy1) {
        return a1+a2;
    }

   return a1+a2-(l*b);


     }
};