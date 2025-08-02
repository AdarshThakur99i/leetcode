class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
    
       unordered_map<int,int> mp;
       int mini=INT_MAX;
       for(int i=0; i<basket1.size(); i++) {
        mp[basket1[i]]++;
        mini=min(mini,basket1[i]);
       }

       for(int i=0; i<basket2.size(); i++) {
        mp[basket2[i]]--;
        mini=min(mini,basket2[i]);
       }
       vector<int> finalList;
       for(auto it: mp) {
             int cost=it.first;
             int count=it.second;
             if((count % 2)!=0) return -1;
             if(count==0) continue;

             for(int i=0; i < abs(count/2); i++) {
                finalList.push_back(cost);
             }
                                 }
                       sort(begin(finalList),end(finalList));
                       long long res=0;
                                 for(int i=0; i<finalList.size()/2; i++) {
     res+=min(2*mini,finalList[i]);
                         }     return res;    
    }
};
//1 1 2 4 //2 2 2 4 
//1 2 3 4  // 1 2 3 5