class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
         unordered_map<char,int> vis;
         unordered_map<int,vector<char>> mp; 

        for(int i=0; i<s1.size(); i++) {
            if(s1[i]==s2[i] && vis.count(s1[i])) {
                continue;
            }
            else if(s1[i]==s2[i] && !vis.count(s1[i])) {
                mp[i].push_back(s1[i]);
                vis[s1[i]]=i;
                continue;
            }
            if(vis.count(s1[i]) && vis.count(s2[i])) {
             int from = vis[s2[i]];
int to = vis[s1[i]];

if (from == to) continue;

for (char ch : mp[from]) {
    mp[to].push_back(ch);
    vis[ch] = to;
}

mp.erase(from);
continue;

    }

    

            
            if(vis.count(s1[i])) {
                mp[vis[s1[i]]].push_back(s2[i]);
                vis[s2[i]]=vis[s1[i]];
                continue;
            }
                if(vis.count(s2[i])) {
                mp[vis[s2[i]]].push_back(s1[i]);
                vis[s1[i]]=vis[s2[i]];
                continue;
            }

            mp[i].push_back(s1[i]);
            mp[i].push_back(s2[i]);
            vis[s1[i]]=i;
            vis[s2[i]]=i;
            
    }

        for(auto &it: mp) {
            sort(begin(it.second),end(it.second));
        }
        string res="";
        for(int i=0; i<baseStr.size(); i++) {
            if(!vis.count(baseStr[i])) {
                res+=baseStr[i];
                continue;
            }
                res+=mp[vis[baseStr[i]]][0];
        }

        return res;
    }
};