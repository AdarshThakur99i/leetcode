class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
         for(int i=0; i<time.size(); i++) {
          time[i] %= 60;
         }
         int cnt=0;
         unordered_map<int,int> mp;
         for(int i=0; i<time.size(); i++) {
            if(time[i]==0 && mp.count(time[i]))  cnt+=mp[time[i]];
           
         
         else {
            if(mp.count(60-time[i])) {
                cnt+=mp[60-time[i]];
            }
         }
         mp[time[i]]++;
}

         return cnt;
    }
};