class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char,int> mp; 
         int bottom=INT_MAX;
         for(int i=0; i<word.size(); i++) {
            mp[word[i]]++;
         } 
        vector<int> count;
     for(auto it: mp) {
        count.push_back(it.second);
     }
     sort(begin(count),end(count));
     int res=INT_MAX;
   
    
      for(int i=0; i<count.size(); i++) {
          int base=count[i];
        int ct=0;   for(int j=0; j<i; j++) {
            ct+=count[j];
          }

          for(int j=i+1; j<count.size(); j++) {
              if(count[j]-base > k ) {
                ct+=count[j]-(base+k);
              }
          }
          res=min(res,ct);
      }
      return res;

         
    }
};
 
