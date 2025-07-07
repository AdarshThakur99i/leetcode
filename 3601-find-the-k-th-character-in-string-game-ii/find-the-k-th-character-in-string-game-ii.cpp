class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
     if(k==1) return 'a';
long long newK=-1;
int operationType=-1;
     long long len=1;
     for(int i=0; i<operations.size(); i++) {
        len *=2;
        if(len>=k) {
            newK=k-(len/2);
            operationType=operations[i];
            break;
        }
     }
     char ch=kthCharacter(newK,operations);

        if(operationType==0) {
            return ch;
        }

        return ch=='z' ? 'a':ch+1;
    }
}; 