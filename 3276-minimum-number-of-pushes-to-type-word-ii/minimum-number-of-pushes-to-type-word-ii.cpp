class Solution {
public:
    int minimumPushes(string word) {
           unordered_map<char,int> mp;
           priority_queue<int> q;
           for(int i=0; i<word.size(); i++) {
            mp[word[i]]++;
           }
           int sum=0;
           for(auto it: mp) {
            q.push(it.second);
            sum+=it.second;
           }
           int curr=0;
           if(mp.size()<=8) return sum;
             int temp=3;
           int extra=mp.size()%8; int val=1;
           while(temp>0) {
           
            for(int i=0; i<8; i++) {
           if (!q.empty()) {
              curr+=(val)*q.top();
              q.pop();


           }
           }
           val++;
           temp--;
           }
           if(!q.empty() && extra>0) {
            while(!q.empty() && extra>0) {
                curr += (4*q.top());
                q.pop();
                extra--;
            }
           }
       
           return curr;
    }
};