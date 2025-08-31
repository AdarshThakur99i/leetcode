class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startpos, int k) {
        
int maxi=0;
        vector<int> pos;
        vector<int> prefsum(fruits.size(),0);
        for(int i=0; i<fruits.size(); i++) {
                pos.push_back(fruits[i][0]);
                prefsum[i]+=fruits[i][1] + (i>0?prefsum[i-1]:0);
        }
        

        for(int d=0; d<=(k/2); d++) {

            int i= startpos-d;
            int j= startpos+(k-2*d);

            int left=lower_bound(begin(pos),end(pos),i)-begin(pos);
            int right=upper_bound(begin(pos),end(pos),j)-begin(pos)-1;

              if(left<=right) {
                   maxi=max(maxi,(prefsum[right]-((left>0)?prefsum[left-1]:0)));
              }


          j=startpos+d;
          i=startpos-(k-2*d);
        
                left=lower_bound(begin(pos),end(pos),i)-begin(pos);
             right=upper_bound(begin(pos),end(pos),j)-begin(pos)-1;

              if(left<=right) {
                   maxi=max(maxi,(prefsum[right]-((left>0)?prefsum[left-1]:0)));
              } }
              return maxi;

    }
};