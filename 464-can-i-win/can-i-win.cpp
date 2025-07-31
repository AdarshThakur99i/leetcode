class Solution {
public:
unordered_map<int,bool> mp;
   bool check(int maxi,int Total,int bitMask) {
         if(mp.count(bitMask)) {
          return mp[bitMask];
         }
         for(int i=1; i<=maxi; i++) {
            int bit=1<<(i-1);
            if((bitMask & bit) == 0) {
                if(i>=Total) return mp[bitMask]=true;
                if(!check(maxi,Total-i,bitMask|bit)) {
                    return mp[bitMask]=true;
                }
            }
         }
         return mp[bitMask]=false;
   }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
          if(desiredTotal<=0) return true;
          int total=maxChoosableInteger*(maxChoosableInteger+1)/2;
          if(desiredTotal>total) return false;
          return check(maxChoosableInteger,desiredTotal,0);

    }
};