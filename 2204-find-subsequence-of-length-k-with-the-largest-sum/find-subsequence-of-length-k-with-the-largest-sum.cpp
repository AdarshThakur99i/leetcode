class Solution {
public:
int maxi=INT_MIN;


    vector<int> maxSubsequence(vector<int>& nums, int k) {
        
        vector<int> ans;
        priority_queue<pair<int,int>> q;
        for(int i=0; i<nums.size(); i++) {
            q.push({nums[i],i});
        }
        vector<vector<int>> temp;
        while(k>0) {
            auto x=q.top();
            q.pop();
            temp.push_back({x.first,x.second});

            k--;
        }
        sort(begin(temp),end(temp),[](const vector<int> &a,const vector<int> &b) {
               return a[1]<b[1];
        });
        for(auto it: temp) {
            ans.push_back(it[0]);
        }
      
       
     
    
      
        return ans;
    }
};