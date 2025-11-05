class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>> vec;
        for(int i=0; i<plantTime.size(); i++) {
            vec.push_back({plantTime[i],growTime[i]});
        }
        sort(begin(vec),end(vec),[](const pair<int,int> &a,const pair<int,int> &b) {
                return a.second>b.second;
        });
              int day=0;
              int maxi=INT_MIN;
              for(int i=0; i<plantTime.size(); i++) {
                    maxi=max(maxi,day+vec[i].first+vec[i].second);
                    day+=vec[i].first;
              }
                 
              return maxi;
    }
};

//3 8 

//3 4 7 6
//3 8 