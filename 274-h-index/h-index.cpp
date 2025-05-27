class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size()==1) {
            if(citations[0]==0) return 0;
            else {
                return 1;
            }
        }
     sort(begin(citations),end(citations));
     
     int mini=INT_MAX;
     int count=0;
     int maxi=INT_MIN;
     int prev=INT_MIN;
     for(int i=citations.size()-1; i>=0; i--) {

              mini=min(mini,citations[i]);
              count++;
              if(mini<count){
                if(prev!=INT_MIN && prev>=(count-1)) {
                   return count-1;
                }
                count=1;
              }
              if(count==mini) break;
              if(i==0 && citations[i]!=0) {
                return count;
              }
              prev=mini;

     }
   if(count!=mini){ count=0;

    unordered_map<int,int> mp;
    for(int i=0; i<citations.size(); i++) {
        if(citations[i]==0) continue;
        mp[citations[i]]++;
        if(citations[i]==mp[citations[i]]) {
            count=citations[i];
            break;
        }
    }
   }
return max(maxi,count);
    }
};