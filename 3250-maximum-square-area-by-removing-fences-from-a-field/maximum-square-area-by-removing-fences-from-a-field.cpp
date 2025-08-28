class Solution {
public:
const int MOD=1e9+7;
    int maximizeSquareArea(int m, int n, vector<int>& h, vector<int>& v) {
               h.push_back(1);
               h.push_back(m);
               sort(begin(h),end(h));
               v.push_back(1);
               v.push_back(n);
               sort(begin(v),end(v));
               unordered_map<int,int> mp;
               for(int i=0; i<h.size(); i++) {
                for(int j=i+1; j<h.size(); j++) {
                    mp[h[j]-h[i]]++;
                }
               }

   long long val=-1;
   for(int i=0; i<v.size(); i++) {
    for(int j=i+1; j<v.size(); j++) {
        if(mp.count(v[j]-v[i])) {
            val=max(val,(long long)(v[j]-v[i]));

        }
    }
   }
   return (val==-1) ? -1:(val*val)%MOD;
        
            }
};