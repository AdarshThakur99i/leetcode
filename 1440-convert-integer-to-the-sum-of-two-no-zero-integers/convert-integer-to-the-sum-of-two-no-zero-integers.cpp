class Solution {
public:
  bool contain(int a,int b) 
  {
    string x=to_string(a);
    string temp=to_string(b);
    for(int i=0; i<x.size(); i++) {
        if(x[i]=='0') return false;
    }
    for(int j=0; j<temp.size(); j++) {
        if(temp[j]=='0') return false;


    }
    return true;
  }
    vector<int> getNoZeroIntegers(int n) {
        vector<int> res;
        for(int i=1; i<=n; i++) {
            int a=i;
            int b=n-i;
            if(contain(a,b)) {
                res.push_back(a);
                res.push_back(b);
                return res;
            }
        }
     return res;
    }
};

//21 