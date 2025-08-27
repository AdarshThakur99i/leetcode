class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
            vector<int> vec=nums;
            sort(begin(vec),end(vec));
            unordered_map<int,int> mp;
            unordered_map<int,list<int>> mp2;

            int group=0;
            mp[vec[0]]=group;
            mp2[group].push_back(vec[0]);

            for(int i=1; i<nums.size(); i++) {
                  if(abs(vec[i]-vec[i-1]) > limit) {
                    group++;
                  }

                  mp[vec[i]]=group;
                  mp2[group].push_back(vec[i]);

            }
            for(int i=0; i<nums.size(); i++) {
                     int grup=mp[nums[i]];
                      int val=*(mp2[grup].begin());
                      mp2[grup].pop_front();
                      nums[i]=val;
               
            }

            return nums;
            
    }
};

