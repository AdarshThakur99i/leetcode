class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       priority_queue<int> q;
       vector<int> mp(26);
       int cnt=0;
       for(int i=0; i<tasks.size(); i++) {
        mp[tasks[i]-'A']++;
       }
         for(int i=0; i<mp.size(); i++) {
            if(mp[i]>0) {
                q.push(mp[i]);
            }
         }  
         while(!q.empty()) {
            vector<int> freq;
            for(int i=1; i<=n+1; i++) {
                if(!q.empty()) {
             int x=q.top();
             q.pop();
             x--;
             freq.push_back(x);}
            }
            for(auto it: freq) {
                if(it>0)  q.push(it);
            }
             if(q.empty()) {
                cnt+=freq.size();
             }
             else {
                cnt+=n+1;
             }

         }
         return cnt;      
    }
};

//5 A  2 B 
// A idel  idel A idel idel A idel idel A B ideal A B ??14
// B A idle B A idle  IDLE  A idele idle A idel idel A
