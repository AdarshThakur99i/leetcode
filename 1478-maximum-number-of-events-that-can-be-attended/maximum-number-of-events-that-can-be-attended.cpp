class Solution {
public:
  
    int maxEvents(vector<vector<int>>& events) {
             sort(begin(events),end(events));
             priority_queue<int,vector<int>,greater<int>> pq;
             int day=events[0][0];

             int cnt=0;
               int maxi=0;
               int i=0;
             
               while(!pq.empty() || i<events.size()) {
                      while( i<events.size() && events[i][0]==day ) {
                        pq.push(events[i][1]);
                        i++;
                      }
                        if(!pq.empty()) {
                            pq.pop();
                           cnt++;
                        } day++;

                        while(!pq.empty() && pq.top() < day) {
                            pq.pop();
                        }
               } 


             return cnt;
    }
};