class Solution {
public:
    const int MOD = 1e9 + 7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        if (forget <= delay)
            return 1;
        queue<pair<int, int>> q;
        q.push({1, 1});
        int day=2;
        while (day<=n) {
            int sz = q.size();
long long newPeople=0;
            while (sz--) {
                auto x = q.front();
                q.pop();
                int cnt = x.first;  
                int time = x.second;
                if(day-time<forget) {
                    q.push({cnt,time});
                }
                if (day-time >= delay && day-time < forget) {
                     newPeople=(newPeople+cnt)%MOD;
                }
               
            }
             if(newPeople>0) q.push({newPeople,day});
            day++;
        }

        long long ans=0;
        while(!q.empty()) {
            int cnt=q.front().first;
            int time=q.front().second;
            q.pop();

            if(n-time <forget) {
                ans=(ans+cnt)%MOD;
            }
        }
        return ans;
    }
};