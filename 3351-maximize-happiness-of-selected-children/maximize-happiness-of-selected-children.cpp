class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
         sort(begin(happiness),end(happiness));
         int i=happiness.size()-1;
         int temp=0;
         long long curr=0;
         long long sum=0;
         while(i>=0) {
            
          int val=happiness[i]-curr;
          if(val>0) sum+=val;
          curr++;

            i--;
            temp++;
            if(temp==k) return sum;
         }
         return sum;
    }
};