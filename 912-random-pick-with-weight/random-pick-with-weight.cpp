class Solution {
public:
   vector<int> prefix;
   int sum=0;
    Solution(vector<int>& w) {
         prefix.resize(w.size(),0);
         sum+=w[0];
          prefix[0]=w[0];
         for(int i=1; i<w.size(); i++) {
           prefix[i] = prefix[i-1] + w[i];
           sum+=w[i];
         }
    }
    
    int pickIndex() {
          int l=0;
          int r=prefix.size()-1;
          int ans=0;
       int pt=rand()%sum+1;
         while(l<r) {  int mid=l+(r-l)/2;
            if(prefix[mid] <pt) {
                l=mid+1;
            }
            else {
                r=mid;
            }
         }
         return r;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */