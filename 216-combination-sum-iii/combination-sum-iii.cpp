class Solution {
public:

   void check(int k,int n,vector<int> &temp,vector<vector<int>> &ans,int currsum,int maxi) {
   
   
            if(temp.size()==maxi) {
                if(currsum==n) {
                    ans.push_back(temp);
                }
                return;
            } if(k>9) return;
     
        temp.push_back(k);
        check(k+1,n,temp,ans,currsum+k,maxi);

        temp.pop_back();
        check(k+1,n,temp,ans,currsum,maxi);
          
   }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<vector<int>> ans;
   check(1,n,temp,ans,0,k);

   return ans;
    }
};