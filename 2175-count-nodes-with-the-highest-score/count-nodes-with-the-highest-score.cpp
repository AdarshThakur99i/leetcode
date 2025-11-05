class Solution {
public:
int n;
     long long dfs(int it,int i,unordered_map<int,vector<int>> &mp,vector<long long> &subtree) {  
                  int temp=1;
                  for(auto k : mp[it])  {
                    if(k != i) {
                        temp +=dfs(k,it,mp,subtree);
                    }
                  }
                  subtree[it]=temp;
                  return temp; 
     }
    long long check(unordered_map<int,vector<int>> &mp,int i,vector<long long> &subtree)  {
             long long temp=1;
             long long remaining=n-subtree[i];
             if(remaining > 0) temp*= remaining;
             for(auto it : mp[i]) {
                temp*=subtree[it];
             }
             return temp;
    }
    int countHighestScoreNodes(vector<int>& parents) {
int m=parents.size();
n=m;
vector<long long> subtree(m,0);
           unordered_map<int,vector<int>> mp;
           for(int i=1; i<parents.size(); i++) {
                   mp[parents[i]].push_back(i);
           }
           dfs(0, -1, mp, subtree); 
           unordered_map<long long,long long> freq;
           for(int i=0; i<parents.size(); i++) {
                freq[check(mp,i,subtree)]++;
           }
          int cnt=0;
           long long maxi=LLONG_MIN;
           for(auto it: freq) {
           if(it.first > maxi) {
            maxi=it.first;
            cnt=it.second;
           }
           else if(it.first == maxi) {
           
            cnt+=it.second;
           }
        
           }
           return cnt;
    }
};