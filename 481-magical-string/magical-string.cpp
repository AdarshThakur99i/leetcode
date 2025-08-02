class Solution {
public:
    int magicalString(int n) {
        string res="122";
        if(n<=3) return 1;
        int cnt=1;
       
       bool check=false;
      int i=2;
       while(n>res.size()) {
        int x=res[i]-'0';
        if(check==false) {
            while(x--) {
res+='1';
cnt++;
   if(res.size()>=n) break;
            }i++;
            check=true;
        }
        else {
            while(x--) {
                res+='2';
            }
            i++;
            check=false;
        }
       }
    return cnt;
     }
};
//4