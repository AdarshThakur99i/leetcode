class Solution {
public:
  const int MOD=1e9+7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> res;
       
       for(int i=0; i<32; i++) {
           int bit=(n>>i)&1;
        if(bit==1) {
            res.push_back(pow(2,i));
        }
       }
      vector<int> ans;
       for(int i=0; i<queries.size(); i++) {
 long long pro=1;
        for(int j=queries[i][0]; j<=queries[i][1]; j++) {
              pro=(pro*res[j]) % MOD;
        }
        ans.push_back(pro);
       }

       return ans;
    }
};