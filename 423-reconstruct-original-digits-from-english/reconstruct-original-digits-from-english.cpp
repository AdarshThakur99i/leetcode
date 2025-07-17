class Solution {
public:
    string originalDigits(string s) {
        unordered_map<char,int> mp;
        vector<int> res(10,0);
        for(int i=0; i<s.size(); i++) {
            mp[s[i]]++;
        }
       res[0]=mp['z'];
       res[2]=mp['w'];
       res[4]=mp['u'];
       res[6]=mp['x'];
       res[8]=mp['g'];
       res[3]=mp['h']-res[8];
       res[5]=mp['f']-res[4];
       res[7]=mp['s']-res[6];
       res[1]=mp['o']-res[0]-res[2]-res[4];
       res[9]=(mp['n']-res[7]-res[1])/2;

        string ans="";
        for(int i=0; i<res.size(); i++) {
            while(res[i]>0) {
                ans+=to_string(i);
                res[i]--;
            }
        }
        return ans;
    }
}; 