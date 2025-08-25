class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& h, vector<int>& v) {
           sort(begin(h),end(h));
           sort(begin(v),end(v));
           long long maxv=INT_MIN;
           long long curr=0;
           long long maxh=INT_MIN;

           for(int i=0; i<v.size(); i++) {
                   if(i+1< v.size() && v[i]+1==v[i+1]) {
                    curr++;
                   }
                   else {
                    maxv=max(maxv,curr+1);
                    curr=0;
                   }
           }
           curr=0;
           for(int i=0; i<h.size(); i++) {
                   if(i+1< h.size() && h[i]+1==h[i+1]) {
                    curr++;
                   }
                   else {
                    maxh=max(maxh,curr+1);
                    curr=0;
                   }
           }

           long long mini=min(maxh,maxv)+1;

           return mini*mini;

    }
};

//5 x 4
// 