class Solution {
public:
    void bfs(unordered_map<int,int> mp,vector<int> &dis,vector<int> &vis,int node) {

        queue<pair<int,int>> q;
        q.push({node,0});
        dis[node]=0;

        while(!q.empty()) {
           int val=q.front().first;
           int dist=q.front().second;
           q.pop();
           if(mp.count(val)) {
            int it=mp[val];
            if(!vis[it]) {
                vis[it]=1;
                if((1+dist)<dis[it]) {
                    dis[it]=1+dist;
                }
                q.push({it,dis[it]});
            }
           }

        }
    }  
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        unordered_map<int,int> mp;
        for(int i=0; i<edges.size(); i++) {
            if(edges[i]==-1) continue;
            mp[i]=edges[i];
        }
        vector<int> dis_1(edges.size(),INT_MAX);
        vector<int> dis_2(edges.size(),INT_MAX);
        int mini=INT_MAX;
        vector<int> vis(edges.size(),0);
        bfs(mp,dis_1,vis,node1);
        fill(vis.begin(), vis.end(), 0);

        bfs(mp,dis_2,vis,node2);
        int idx=-1;
        for(int i=0; i<dis_1.size(); i++) {
            if(dis_1[i]!=INT_MAX && dis_2[i]!=INT_MAX) {
            int maxi=max(dis_1[i],dis_2[i]);
            if(maxi<mini) {
                mini=maxi;
                idx=i;
            }}
        }
        return idx;

    }
};