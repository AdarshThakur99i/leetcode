class Solution {
public:
    int check(vector<int>& vals) {
            int cnt=0;
            int cons=0;
        for(int i=0; i<vals.size(); i++) { 
                 
                  if( vals[i]==1) {
                    cons++;
                  }
                  else {
                    cons=0;
                  }
                  cnt+=cons;
        }
        return cnt;
    }
    int numSubmat(vector<vector<int>>& mat) {
        int ans=0;
        for(int start=0; start<mat.size(); start++) {
            vector<int> vals(mat[0].size(),1);   
        for(int end=start; end<mat.size(); end++) {   
        for(int i=0; i<mat[0].size(); i++) {
                  vals[i]=(vals[i] & mat[end][i]);
                }
                ans+=check(vals);
            }
        }
        return ans;
    }
};