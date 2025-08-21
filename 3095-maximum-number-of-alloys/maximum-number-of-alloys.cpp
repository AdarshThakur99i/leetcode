class Solution {
public:
       bool check(int n,int k,int budget,vector<vector<int>>& compositions,vector<int>& stock,vector<int>& cost,int mid) {
                for(int i=0; i<compositions.size(); i++) {
                    long long totalCost=0;
                    for(int j=0; j<compositions[i].size(); j++) {
                        long long required=(1LL*compositions[i][j]*mid);
                        long long needtobuy=max(0LL,required-stock[j]);
                        totalCost+= needtobuy*cost[j];
                    }
             if(totalCost<=budget) return true;
                }
                return false;
       }
       int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
         int l=0;
         int r=1e9;
         int ans=-1;
         while(l<=r) {
           int mid=l+(r-l)/2;
             if(check(n,k,budget,composition,stock,cost,mid)) {
                ans=mid;
                l=mid+1;
             }
             else {
                r=mid-1;
             }

         }         
       return ans;
    }
};