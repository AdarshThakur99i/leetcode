class Solution {
public:
//     int dfs(string& word,string& temp,int i) {

// if(i==word.size()) {
//     return 0;
// }
// int cnt=0;
//         if(i+1 < word.size() &&( word[i+1]==word[i]  || word[i+1]+1 ==word[i] || word[i]+1==word[i+1])) {
//                 for(char j='a'; j<='z'; j++) {
//                     if(word[i]==j) continue;
//                     temp.push_back(j);
//                    cnt=1+ dfs(word,temp,i+1);
//                     temp.pop_back();

//                 }
//         }
//         temp.push_back(word[i]);
//         int cnt2=dfs(word,temp,i+1);
//         temp.pop_back();

// return min(cnt2,cnt);
//     }
    int removeAlmostEqualCharacters(string word) {
        int ans=0;
         for(int i=0; i<word.size(); i++) {
            if(i+1<word.size()) {
                if(word[i]==word[i+1] || word[i]+1==word[i+1] || word[i+1]+1==word[i]) {
                  ans++;
                  i++;
                }
            }
         }
      
         return ans;
    }
};