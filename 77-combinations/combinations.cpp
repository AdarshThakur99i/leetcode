class Solution {
public:
void solve(int idx,int n,int k,vector<int> &temp,vector<vector<int>> &ans) {
    if(idx==n+2 || temp.size()>k) return;
    if(temp.size()==k) {
       ans.push_back(temp);
       return;
    }

    temp.push_back(idx);
    solve(idx+1,n,k,temp,ans);
    temp.pop_back();
    solve(idx+1,n,k,temp,ans);
}
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> ans;
solve(1,n,k,temp,ans);
return ans;
    }
};