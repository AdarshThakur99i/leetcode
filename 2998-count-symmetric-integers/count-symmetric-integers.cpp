class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt=0;
        for(int i=low; i<=high; i++)  {
              string x=to_string(i);
          
              if(x.size()%2!=0) continue;

              int k=0;
              int j=x.size()-1;
              int sum1=0;
              int sum2=0;
while(k<=j) {
          sum1+=x[k]-'0';
          sum2+=x[j]-'0';
          k++;
          j--;
}
if(sum1==sum2) cnt++;
        }


        return cnt;
    }
};