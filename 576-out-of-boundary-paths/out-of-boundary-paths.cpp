class Solution {
public:
const int MOD=1e9+7;
unordered_map<string,int> mp;
    int check(int i,int j,int m,int n,int maxMove) {
        
            if((i<0 || i>=m || j<0 || j>=n) ) {
                if(maxMove>=0)  return 1;
                return 0;
              
            } if(maxMove<0) return 0;
string key= to_string(i)+','+to_string(j) + ','+ to_string(maxMove);
if(mp.count(key)) {
    return mp[key];
}
         long long res=0;
           int delRow[]={1,0,-1,0};
           int delCol[]={0,1,0,-1};
           for(int k=0; k<4; k++) {
            int newRow=i+delRow[k];
            int newCol=j+delCol[k];
            res= (res+check(newRow,newCol,m,n,maxMove-1))%MOD;
           }
           return mp[key]=res;
           

    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
          return check(startRow,startColumn,m,n,maxMove);
    }
};