class Solution {
public:
vector<vector<int>> points;
vector<int> prefix;
long long total=0;
    Solution(vector<vector<int>>& rects) {
        points=rects;

        for(int i=0; i<rects.size(); i++) {
            int pointsx=rects[i][2]-rects[i][0]+1;
            int pointsy=rects[i][3]-rects[i][1]+1;
            total+= (pointsx)*(pointsy);
            prefix.push_back(total);
        }
    }
    
    vector<int> pick() {
       int point=rand()%total;
       int idx=upper_bound(begin(prefix),end(prefix),point)-begin(prefix);
        int x1=points[idx][0]; int y1=points[idx][1]; int x2=points[idx][2];
        int y2=points[idx][3];
       int sz=point-((idx==0)?0:prefix[idx-1]);
       int wt=x2-x1+1;
       int row=sz/wt;
       int col=sz%wt;
        return {col+x1,row+y1};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */