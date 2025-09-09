class Solution {
public:
    int minimumLevels(vector<int>& possible) {
      int one=0;
      int zero=0;
      for(int i=1; i<possible.size(); i++) {
        if(possible[i]==1) one++;
        else {
            zero++;
        }
      }
      int i=1;
      int alicescore=(possible[0]==0)?-1:1;
      int bobscore=one-zero;
      if(alicescore>bobscore) return 1;
      while(i<possible.size()) {
           if(alicescore<=bobscore) {
                    if(possible[i]==1) {
                        alicescore+=1;
                        bobscore-=1;
                    }
                    else {
                        alicescore-=1;
                        bobscore+=1;
                    }
           }
           else {
            return i;
           }

        i++;
      }
      return -1;  
    }
};