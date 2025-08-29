class Solution {
public:
//    unordered_map<int,int> dp;
//     int check(int x,int y) {
   
//       if(x==y ) return 0;
//      if (x <= 0 || x > 2 * max(x, y)) return 1e7;
// if(dp.count(x)) return dp[x];
//          int divide=1e6;
//         if(x>y && (x%11) ==0) {
//             divide=1+check((x/11),y);
//         }
//         int dividef=1e6;
//         if(x>y && (x%5) ==0) {
//             dividef=1+check(x/5, y);
//         }
//         int dec=1e6;
//         if(x>y) {
//         dec=1+check(x-1,y);}
       
      
//            int inc=1+check(x+1,y);
        
//         return dp[x]=min({divide,dividef,dec,inc});



//     }
    int minimumOperationsToMakeEqual(int x, int y) {
            queue<long long> q;
            unordered_set<long long> vis;
            q.push(x);
int cnt=0;
            while(!q.empty()) {
                int sz=q.size();
                while(sz--) {
                long long val=q.front();
                q.pop();
                if(val==y) return cnt;
               
                 if(val>y && val%11 ==0 && vis.find(val%11)==vis.end()) {
                    vis.insert(val/11);
                    q.push(val/11);
                 }
                 if(val>y && val%5 ==0 && vis.find(val%5)==vis.end()) {
                    vis.insert(val/5);
                    q.push(val/5);
                 }
                 if(val>y && vis.find(val-1)==vis.end()) {
                    vis.insert(val-1);
                    q.push(val-1);
                 }
                 if(vis.find(val+1)==vis.end()) {
                    vis.insert(val+1);
                 q.push(val+1);}
                }
                cnt++;
            }
            return cnt;
    }
};