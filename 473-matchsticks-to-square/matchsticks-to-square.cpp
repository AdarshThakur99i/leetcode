class Solution {
public:
    bool check(vector<int> &matchsticks,vector<int> &sides,int idx,int target) {
        if(idx==matchsticks.size()) {
        if(sides[0]==target && sides[1]==target && sides[2]==target && sides[3]==target) {
            return true;
        }
        return false;}

        for(int i=0; i<4; i++) {
            if(sides[i]+matchsticks[idx]<=target) {
                sides[i]+=matchsticks[idx];
                if(check(matchsticks,sides,idx+1,target)) {
                    return true;
                }
                sides[i]-=matchsticks[idx];
            }
            if(sides[i]==0) break;
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
       int total=0;
       for(int i=0; i<matchsticks.size(); i++) {
        total+=matchsticks[i];
       }
       int n=total/4;
       if(total%4 !=0) return false;
       sort(rbegin(matchsticks),rend(matchsticks));
       vector<int> sides(4,0);
return check(matchsticks,sides,0,n);
    }
};