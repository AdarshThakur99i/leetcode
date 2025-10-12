class Solution {
public:

    int check(char x,char y,string s) {
        unordered_map<int,int> mp;
      
int maxi=1;
        int sum=0;
        mp[0]=-1;
        for(int i=0; i<s.size(); i++) {
            if(s[i]==x) sum++;
          else  if(s[i]==y) sum--;
            else {
                    mp.clear();
                    sum=0;
            }

            if(mp.count(sum)) {

                maxi=max(maxi,i-mp[sum]);
                continue;
            }
            mp[sum]=i;
        }
        return maxi;

    }
    int longestBalanced(string s) { 
       map<pair<int,int>,int> mp;
       vector<int> count(3,0);
       int maxi=1;
       int len=1;
  for(int i=1; i<s.size(); i++) {
          if(s[i]==s[i-1]) {
            len++;
          }
          else {
            maxi=max(maxi,len);
        
            len=1;
            
          }
  }
  maxi=max(maxi,len);
       int x1=check('a','b',s);
       int x2=check('b','c',s);
       int x3=check('a','c',s);

       mp[{0,0}]=-1;
    

      
       
       for(int i=0; i<s.size(); i++) {
               if(s[i]=='a') {
                  count[0]++;
               }
             else  if(s[i]=='b') {
                    count[1]++;
               }
               else {
               count[2]++;
               }
               int x=count[0]-count[1];
               int y=count[0]-count[2];
              if(mp.count({x,y})) {
               maxi=max(maxi,i-mp[{x,y}]);
               continue;
              }
               mp[{x,y}]=i;
       }
       return max({maxi,x1,x2,x3});
    }
};