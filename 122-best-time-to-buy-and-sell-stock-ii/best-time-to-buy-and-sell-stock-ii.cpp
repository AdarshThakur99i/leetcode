class Solution {
public:


    int maxProfit(vector<int>& prices) {
         
int profit=0;
         for(int i=0; i<prices.size()-1; i++) {
                if(prices[i+1]>prices[i]) {
                    int j=i;
                    i++;

                    while(i<prices.size() && prices[i]>=prices[i-1]) {
                        i++;
                    }
                    i--;
                    profit+=prices[i]-prices[j];

                }
               
            }

            return profit;

  }
};