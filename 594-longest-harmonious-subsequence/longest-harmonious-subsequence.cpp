class Solution {
public:
// unordered_map<string,int> mp;
//    int check(vector<int> &nums,int i,long long maxi,long long mini,int cnt) {
//         if(i==nums.size()) {
//             if((maxi-mini)==1) {
               
//                 return cnt;
//             }
//             return 0;
//         }string key=to_string(i)+','+to_string(maxi)+','+to_string(mini) +','+to_string(cnt);
//         if(mp.count(key)>0) {
//             return mp[key];
//         }
        
//    long long tempM=maxi;
//    long long tempm=mini;
//     maxi=max(maxi,static_cast<long long>(nums[i]));
//     mini=min(mini,static_cast<long long>(nums[i]));
//     long long take=check(nums,i+1,maxi,mini,cnt+1);
//     long long not_take=check(nums,i+1,tempM,tempm,cnt);

//     return mp[key]=max(take,not_take);
    

//    }
    int findLHS(vector<int>& nums) {
        
    unordered_map<int,int> mp;
    for(int i=0; i<nums.size(); i++) {
        mp[nums[i]]++;
    }
    int maxi=INT_MIN;
    for(int i=0; i<nums.size(); i++) {
        if(mp.count(nums[i]+1) >0) {
            maxi=max(maxi,(mp[nums[i]]+mp[nums[i]+1]));
        }
    }
        return (maxi==INT_MIN) ? 0 : maxi;
        
        
    }
};