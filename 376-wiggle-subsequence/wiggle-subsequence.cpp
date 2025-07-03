class Solution {
public:
unordered_map<string,int> mp;
    int checke(vector<int>& nums,int i,int check,int prev) {
                 if(i==nums.size()) {
                    return 0;
                 }
     int take=0;
     string key=to_string(i)+','+to_string(check)+','+to_string(prev);
     if(mp.count(key)) {
        return mp[key];
     }
     if(prev==INT_MAX) {
          take=1+checke(nums,i+1,INT_MAX,nums[i]);
     }
    else if(check==INT_MAX ) {
        if((nums[i]-prev)<0) {
        take=1+checke(nums,i+1,-1,nums[i]);}
        else if((nums[i]-prev)==0) {

        }
        else {
            take=1+checke(nums,i+1,1,nums[i]);
        }
     }
       else if((nums[i]-prev) <0 && check>0) {
take=1+checke(nums,i+1,-1,nums[i]);
        }
        else if((nums[i]-prev) >0 && check<0) {
            take=1+checke(nums,i+1,1,nums[i]);
        }
        
         
        int not_take=checke(nums,i+1,check,prev);

        return mp[key]=max(take,not_take);
    }
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()==1) return 1;
        if(nums.size()==2) {
            if(nums[0]!=nums[1]) return 2;
            return 1;
        }
      int res=INT_MIN;
      
      return checke(nums,0,INT_MAX,INT_MAX);
        
    }
};