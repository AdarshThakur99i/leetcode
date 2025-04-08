class Solution {
 
public:

   
    int minimumOperations(vector<int>& nums) {
    unordered_map<int,int> mp;
        int j=0;
        int cnt=0;
        int temp=0;
       for(int i=0; i<nums.size(); i++) {
       mp[nums[i]]++;
        if(mp[nums[i]]>1) {
            while((mp[nums[i]]>1 || temp%3!=0)) {
                mp[nums[j]]--;
                temp++;

                j++;
                if(j==nums.size()) {
                    cnt+=(temp+2)/3;
                    return cnt;
                }
            }
       
           
            cnt+=(temp+2)/3;
            temp=0;

        
         
           
        }

        

       }
       return cnt;
       
       
    }
};