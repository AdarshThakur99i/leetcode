class Solution {
public:


//    void check(unordered_map<int,vector<pair<int,int>>> &mp,int i ,int time,vector<int> &disappear) {
//         if(ans[i]==-1) ans[i]=time;
//         else  ans[i]=min(ans[i],time);
         
//         for(auto it: mp[i]) {
//             int b=it.first;
//             int wt=it.second;
//             if(wt+time < disappear[b]) {
//                 check(mp,b,time+wt,disappear);
//             }
//         }
//    }
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        unordered_map<int,vector<pair<int,int>>> mp;

        for(int i=0; i<edges.size(); i++) {
                 int a=edges[i][0];
                 int b=edges[i][1];
                 int wt=edges[i][2];
                 mp[a].push_back({b,wt});
                 mp[b].push_back({a,wt});
        }
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> q;
       q.push({0,0});
       vector<int> dis(n,INT_MAX);
dis[0]=0;
       while(!q.empty()) {

        auto x=q.top();
        q.pop();
        int time=x.first;
        int i=x.second;
     
       if(time>=disappear[i]) continue;
       if(time>dis[i]) continue;
        for(auto it: mp[i]) {
            int wt=it.second;
            if(time+wt < disappear[it.first] && time+wt < dis[it.first]) {dis[it.first]=min((time+wt),dis[it.first]);
                q.push({time+wt,it.first});
            }
        }
       }
       for(auto &it: dis) {
        if(it==INT_MAX) it=-1;
       }
        return dis;
    }
};