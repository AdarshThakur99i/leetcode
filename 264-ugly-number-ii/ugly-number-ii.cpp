class Solution {
public:
    int nthUglyNumber(int n) {
        int i=0;
        vector<int> arr(n+1,0);
        arr[1]=1;
        int i2=1;
        int i3=1;
        int i5=1;

         for(int i=2; i<=n; i++) {
                
            int ugly1=arr[i2]*2;
            int ugly2=arr[i3]*3;
            int ugly3=arr[i5]*5;

            int mini=min({ugly1,ugly2,ugly3});
            arr[i]=mini;
            if(mini==ugly1) {
                i2++;
            }
            if(mini==ugly2) {
                i3++;
            }
            if(mini==ugly3) {
                  i5++; 
            }
          


         }
         return arr[n];
    }
};