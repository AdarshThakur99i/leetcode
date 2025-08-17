class Solution {
public:

//    bool check(vector<int> &nums,int m,int sum) {
//           if(nums.size()==2) return true;
//         //   if(sum<m) return false;
//            int x=nums.back(); 
//            bool take_back=false;
//         if((sum-x) >= m) {
//             nums.pop_back();
//             take_back=check(nums,m,sum-x);
//             nums.push_back(x);

//         }
//         bool take_front=false;
//         int temp=nums[0];
//         if((sum-nums[0]) >=m) {
//               nums.erase(nums.begin());
//               take_front=check(nums,m,(sum-temp));
//               nums.insert(nums.begin(),temp);
//         }

//         return (take_back || take_front);
          

//    }
    bool canSplitArray(vector<int>& nums, int m) {
        if(nums.size() <=2) return true;
        //   int sum=accumulate(nums.begin(),nums.end(),0);
        //  return check(nums,m,sum);

        for(int i=0; i+1<nums.size(); i++) {
            if(nums[i]+nums[i+1] >= m) {
                return true;
            }
        }
        return false;
    }

};