class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        // if(currentEnergy==0) return 0;
          long long cnt=0;
          sort(begin(enemyEnergies),end(enemyEnergies));
          int i=0;
          int j=enemyEnergies.size()-1;
          long long curr=currentEnergy;
          while(i<=j) {

            if(curr >= enemyEnergies[i]) {
                cnt+= (curr)/enemyEnergies[i];

                  curr=(curr)%(enemyEnergies[i]);
                
                
            }
            else if(cnt>=1) {
                  curr=curr+enemyEnergies[j];
                  j--;
            }
            else {
                break;
            }
          }
          return cnt;
    }
};