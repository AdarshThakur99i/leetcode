class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> q;
long long total=0;
           for(int i=0; i<nums.size(); i++) {
                q.push({nums[i],i});
                total+=nums[i];
           }
           vector<long long> res;
             unordered_set<long long> st;
           for(int i=0; i<queries.size(); i++) {
                 int a=queries[i][0];
                 int k=queries[i][1];
                 if(st.find(a)==st.end()) {
                     total-=nums[a];
                 }
                 st.insert(a);
                 
                
                 while(!q.empty() && k>0) {
                    if(!q.empty() && st.find(q.top().second)==st.end()) {
                          total-=q.top().first;
                          st.insert(q.top().second);
                          q.pop();
                          k--;
                    }
                    else {
                        if(!q.empty()) q.pop();
                        
                    }
                 
                     
                 }
                 
                 res.push_back(total);

           }

           return res;
    }
};