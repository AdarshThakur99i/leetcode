class Solution {
public:
long long Count(long long curr,long long next,int n) {
       long long countNum=0;
       while(curr<=n) {
        countNum+=(next-curr);
        curr*=10;
        next*=10;
        next=min(static_cast<int>(next),n+1);
       }
       return countNum;
}
    int findKthNumber(int n, int k) {
        long long curr=1;
        k-=1;
        while(k>0) {
            int count=Count(curr,curr+1,n);
            if(count<=k) {
                curr++;
                k-=count;
            }
            else {
                curr *=10;
                k-=1;
            }
        }
        return curr;
    }
};