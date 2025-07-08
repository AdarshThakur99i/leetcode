class Solution {
public:
    int lengthLongestPath(string input) {
           unordered_map<int,int> mp;
           stringstream ss(input);
           string line;
     
        int maxi=0;
           while(getline(ss,line)) {
                   int level=0;    
                while(line[level]=='\t') level++;

                   string s=line.substr(level);

                   if(s.find('.')==string::npos) {
                    mp[level]=mp[level-1]+s.size()+1;

                   }

                   else {
                    mp[level]=mp[level-1]+s.size();
                    maxi=max(maxi,mp[level]);
                   }
           }
           return maxi;
    }
}; 