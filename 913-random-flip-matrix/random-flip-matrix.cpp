class Solution {
public:
   unordered_map<int,int> mp;
   int m,n,total;
    Solution(int m, int n) {
      this->m=m;
      this->n=n;
      total=m*n;
    }
    
    vector<int> flip() {
         int r=rand()%total;
         int x=(mp.count(r)?mp[r]:r);
         while(mp.count(x)) {
            x=mp[x];
         }
         mp[r]=(mp.count(total-1)? mp[total-1]:total-1);

         total--;

         return {x/n,x%n};
    }
    
    void reset() {
     mp.clear();
     total=m*n;
       
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */