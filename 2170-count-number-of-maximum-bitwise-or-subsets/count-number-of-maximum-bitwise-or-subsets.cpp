class Solution {
public:
      unordered_map<string,int> mp;
    int check(vector<int> &nums,int &maxi,int i,int currOrr) {
    
             if(i==nums.size()) {
                if(currOrr>maxi) {
                    maxi=currOrr;
                   return 1;
                }
                else if(currOrr==maxi) {
                 
                    return 1;
                }
                else {
                    return 0;
                }
               
             }
             string key=to_string(maxi)+','+to_string(i)+','+to_string(currOrr);
             if(mp.count(key)) {
                return mp[key];
             }
                  
           int take=  check(nums,maxi,i+1,currOrr | nums[i]);
           int not_take=  check(nums,maxi,i+1,currOrr);
         return mp[key]=take+not_take;

    }
    int countMaxOrSubsets(vector<int>& nums) {
      int maxi=INT_MIN;
      int cnt=0;
      
     int res= check(nums,maxi,0,0);
      return res;

    }
};