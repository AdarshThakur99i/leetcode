class Solution {
public:
    int minimumSum(int n, int k) {
        vector<int> temp;
        int cnt=1;
        
        while(temp.size() !=n) {
             if(temp.size()==0) {
                temp.push_back(cnt);
             }
             else {
                bool check=false;
                for(int i=0; i<temp.size(); i++) {
                    if(temp[i]+cnt == k)  {
                        check=true;
                        break;
                    }

                }
                if(check==false) {
                    temp.push_back(cnt);
                }
             }


             cnt++;
        }
      int sum=accumulate(temp.begin(),temp.end(),0);
      return sum;
    }
};

//