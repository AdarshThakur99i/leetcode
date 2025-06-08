class Solution {
public:
    void check(int n,int i,vector<int> &temp) {
        if(i>n) return;

        temp.push_back(i);
        int tempo=0;

        for(int j=0; j<=9; j++) {
            tempo=10*i+j;

            if(tempo>n) {
                return;
            }
            check(n,tempo,temp);
     
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> temp;
        for(int i=1; i<=9; i++) {
             check(n,i,temp);
        }
        return temp;

        
    }
};