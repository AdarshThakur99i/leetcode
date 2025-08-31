class Solution {
public:
  vector<int> ans,path,div;
  int K;
    void check(int n) {
            if(path.size()==K) {
                if(n!=1) return;
                if(ans.empty() || (path.back()-path[0] < ans.back()-ans[0])) {
                    ans=path;
                    
                }
                return;
            }

            for(int x: div) {
                if(n%x==0 &&  (path.empty() || x>=path.back())) {
                        path.push_back(x);
                        check(n/x);
                        path.pop_back();
                }
            }
    }
    vector<int> minDifference(int n, int k) {
       
       K=k;
        for(int i=1; i*i<=n; i++){
             if(n%i ==0) {
                div.push_back(i);
             }
             if(i*i != n) div.push_back(n/i); 

        }

        sort(begin(div),end(div));
check(n);
        return ans;
    }
};

// 100 5  2 4 

// 2 2 5 5 