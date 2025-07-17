class Solution {
public:
// unordered_map<int,unordered_map<int,int>> mp;
//     int check(vector<int> &nums,int k,int i,int prev,int diff) {
//           if(i==nums.size()) {
//             return 0;
//           }
//           int key=(prev<<10) | (diff+1);
//           if(mp[i].count(key)) {
//                 return mp[i][key];
//           }
// int take=0;
//         if(diff==-1 || (nums[i]+nums[prev])%k == diff) {
//             int temp=diff;
//          if(diff==-1) {
//             temp=(nums[i]+nums[prev])%k;
//          }
//           take=1+check(nums,k,i+1,i,temp);
//         }
//         int not_take=check(nums,k,i+1,prev,diff);

//         return mp[i][key]=max(take,not_take);
//     }
    int maximumLength(vector<int>& nums, int k) {
        if(nums.size()==2) return 2;
        int maxi=1;
         vector<vector<int>> dp(nums.size(),vector<int>(k+1,1));
        for(int i=0; i<nums.size(); i++) {
            for(int j=0; j<i; j++) {
               int md=(nums[i]+nums[j])%k;
               dp[i][md]=max(dp[i][md],(dp[j][md]+1));
               maxi=max(maxi,dp[i][md]);
            }
        }

         return maxi;
    }
};