class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int cnt=0;
         for(int i=0; i<points.size(); i++) {
            int a=points[i][0];

            int b=points[i][1];
            for(int j=0; j<points.size(); j++) {
                if(i==j) continue;
                   int c=points[j][0];
                   int d=points[j][1];
                   if((c<=a && d>=b)) {
                          int maxx=max(a,c);
                          int minx=min(a,c);
                          int maxy=max(b,d);
                          int miny=min(b,d);

                          int t=0;
                          bool ok=true;
                          while(t<points.size()) {
                            if(t==i || t==j) {
                                t++;
                                continue;
                            }
                            if((points[t][0] <= maxx && points[t][0]>=minx) && (points[t][1]>=miny && points[t][1]<=maxy)) {
                                ok=false;
                                break;
                            }

                            t++;
                          }
                          if(ok==true){
                            cnt++;
                          }
                   }
            }
         }
         return cnt;
    }
};