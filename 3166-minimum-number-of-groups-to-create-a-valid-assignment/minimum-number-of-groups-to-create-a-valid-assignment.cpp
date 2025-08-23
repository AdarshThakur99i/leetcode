class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& balls) {
        unordered_map<int,int> mp;
        long long mini=LLONG_MAX;
        long long maxi=LLONG_MIN;
        for(int i=0; i<balls.size(); i++)  {
            mp[balls[i]]++;
           
        }
  long long ans=LLONG_MAX;
        for(auto it: mp) {
        
             mini=min(mini,(long long)it.second);
          
            maxi=max(maxi,(long long)it.second);
          
        }   for(int k=1; k<=mini; k++) {
        long long sum=0;
        bool ok=true;
        for(auto it: mp) {
            int x=it.second;
            int groups=(x+k)/(k+1);
            if(x<groups*k) {
                ok=false;
                break;
            }

           sum+=groups;
        }
        if(ok==true) {
            ans=min(ans,sum);
        }}
        return ans;

    }
};

// 111 111 111 11
//3
