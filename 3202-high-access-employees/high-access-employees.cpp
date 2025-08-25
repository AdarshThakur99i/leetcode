class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
            unordered_map<string,vector<int>> mp;

            for(int i=0; i<access_times.size(); i++) {
       string name=access_times[i][0];
       int time=stoi(access_times[i][1].substr(0,2))*60 + stoi(access_times[i][1].substr(2,2));
       mp[name].push_back(time);
            }
vector<string> ans;
            for(auto &[name,time]: mp) {
                sort(begin(time),end(time));
                for(int i=0; i+2<time.size(); i++) {
                      if(time[i+2]-time[i] < 60) {
                        ans.push_back(name);
                        break;
                      }
                }
            }
            return ans;
    }
};