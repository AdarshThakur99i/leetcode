class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        int sign=1;
        if(n%2==0) {
            int temp=1;
            for(int i=0; i<n; i++) {
                res.push_back(sign*temp);
                sign=sign*(-1);
                if(res.back()<0)temp++;
            }
        }
        else {
            res.push_back(0);
            int temp=1;
            for(int i=0; i<(n-1); i++) {
                res.push_back(sign*temp);
                sign=sign*(-1);
                if(res.back()<0) temp++;
            }
        }
        return res;
    }
};