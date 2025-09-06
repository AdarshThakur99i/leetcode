class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
       priority_queue<long long,vector<long long>,greater<>> q;
       
    for(int i=0; i<nums.size(); i++) {
        q.push(nums[i]);
    } if(q.top()>=k) return 0;
    int cnt=0;
         while(!q.empty()) {
            if(q.top()>=k) return cnt;
            long long a=q.top();
            q.pop();
           long long b=q.top();
            q.pop();
           long long prev=min(a,b)*2 + max(a,b);
            q.push(prev);
            cnt++;
           
         }
return cnt;
    }
};


