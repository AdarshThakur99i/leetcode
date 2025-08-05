class Solution {
public:
int cnt=0;
    void check(int n,vector<int> &temp,int bitMask) {

        if(temp.size()==n) {
            cnt++;
            return;
        }
        for(int i=1; i<=n; i++) {
            int bit=1 << (i-1);
            if((bitMask & bit)==0) {

                   if(((temp.size()+1) % i)==0 || ((i%(temp.size()+1)) ==0))  {
                       temp.push_back(i);
                   
                   check(n,temp, bitMask | bit);
                   temp.pop_back();}
            }

        }
    }
    int countArrangement(int n) {
     vector<int> temp;
     check(n,temp,0);
     return cnt;
    }
};