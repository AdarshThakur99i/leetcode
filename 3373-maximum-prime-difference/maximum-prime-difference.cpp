class Solution {
public:

   void seive(vector<int>& ans) {

    ans[0]=0;
    ans[1]=0;
    for(int i=2; i*i<ans.size(); i++) {
        if(ans[i]==1) {
         for(int j=i*i; j<ans.size(); j+=i) {
               ans[j]=0;
         }
        }
    }
   }
    int maximumPrimeDifference(vector<int>& nums) {
    int n=*max_element(begin(nums),end(nums));
    vector<int> ans(n+1,1);
    seive(ans);
    vector<int> primes;
    for(int i=0; i<nums.size(); i++) {
        if(ans[nums[i]]==1) {
            primes.push_back(i);
        }
    }
    sort(begin(primes),end(primes));

    return abs(primes.back()-primes[0]);
    }
};