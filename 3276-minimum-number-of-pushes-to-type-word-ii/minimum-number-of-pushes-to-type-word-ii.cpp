class Solution {
public:
    int minimumPushes(string word) {
           unordered_map<char,int> mp;
           priority_queue<int> q;
           for(int i=0; i<word.size(); i++) {
            mp[word[i]]++;
           }
     
           for(auto it: mp) {
            q.push(it.second);
    
           }
           int curr=0;

          int cnt=0;
        int val=1;
           
           
        
           while (!q.empty()) {
              curr+=(val)*q.top();
              q.pop();
              cnt++;
             if(cnt%8==0)val++;

           }
           
          
          
           
       
       
           return curr;
    }
};