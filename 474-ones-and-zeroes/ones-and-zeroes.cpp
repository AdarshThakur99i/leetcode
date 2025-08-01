class Solution {
public:
unordered_map<string,int> mp;
    int check(vector<string> &strs,int m,int n,int i,int ones,int zeros) {
        if(i==strs.size()) {
            if(zeros <=m && ones<=n) {
                return 0;
            }
            return INT_MIN;
        }
        string key=to_string(i)+','+to_string(ones)+','+to_string(zeros);
if(mp.count(key)) {
    return mp[key];
}
        int take=0;
        
        int one=0;
        int zero=0;
        for(int j=0; j<strs[i].size(); j++) {
            if(strs[i][j]=='1') one++;
            if(strs[i][j]=='0') zero++;
        }
        if(one+ones<=n && zero+zeros <=m) {
            take=1+check(strs,m,n,i+1,ones+one,zeros+zero);
        }
        int not_take=check(strs,m,n,i+1,ones,zeros);
        return mp[key]=max(take,not_take);
        
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
           return check(strs,m,n,0,0,0);
    }
};