class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
         sort(begin(players),end(players));
         sort(begin(trainers),end(trainers));
         int i=0;
         int j=0;
         int cnt=0;
         while(i<players.size() && j<trainers.size()) {
                if(players[i]<=trainers[j]) {
                    cnt++;
                    i++;
                    j++;
                }
              else  if(players[i]>trainers[j]) {
                j++;
              }
         }
         return cnt;
    }
};