class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;
        for(int i=0; i<answers.size(); i++) {
        mp[answers[i]]++;
        }
        int cnt=0;

        for( auto &it: mp){
       
        int groupsize=it.first+1;
        int num=(groupsize+it.second-1)/groupsize;

        cnt+=num*groupsize;

     
           

        }


return cnt;

    }
};