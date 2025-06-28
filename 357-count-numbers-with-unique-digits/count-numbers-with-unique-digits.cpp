class Solution {
public:
    void check(string x,int maxSize,int &cnt,vector<int> &vis) {
       
              if(x.size()>=maxSize) return;
           for(int i=0; i<=9; i++) {
            string p=to_string(i);
         
          
          
            if(!vis[i]) {
                vis[i]++;
                cnt++;
            check(x+p,maxSize,cnt,vis);
            vis[i]--;}
           }
      
    }
    int countNumbersWithUniqueDigits(int n) {
       if(n==0) return 1;
        int cnt=0;
       
        for(int i=1; i<=9; i++) { vector<int> vis(10,0);
            vis[i]=1;
            cnt++;
            string a=to_string(i);
           check(a,n,cnt,vis);

        }
        int res=cnt;
        return res+1;
        
    }
};