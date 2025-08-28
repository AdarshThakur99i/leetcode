class Solution {
public:
 
    bool isPalid(long long x) {
        string temp=to_string(x);

        int i=0;
        int j=temp.size()-1;
        while(i<j) {
            if(temp[i]!=temp[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    long long minimumCost(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n=nums.size();
         long long mid= nums[n/2];
         long long l=mid;
         long long r=mid;

         while(l>0 && !isPalid(l)) {
            l--;
         }
         while(r<1e10 && !isPalid(r)) {
            r++;
         }
    
         long long cost=LLONG_MAX;
         for(auto it:{l,r}) {
          long long sum=0;   for(int i=0; i<nums.size(); i++) {
            sum+=abs(nums[i]-it);

            
        }
        cost=min(cost,sum);


         } 
         return cost;

    }
};