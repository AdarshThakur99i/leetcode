class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
      
    unordered_map<int,int> mp;
        for(int i=0; i<board.size(); i++) {
         
            
          
            for(int j=0; j<board[i].size(); j++) {
                if(mp.count(board[i][j])) {
                    return false;
                }
               if(isdigit(board[i][j]))  mp[board[i][j]]++;
            }
            mp.clear();
        }
        mp.clear();
        for(int j=0; j<board[0].size(); j++) {
            for(int i=0; i<board.size(); i++) {
                  if(mp.count(board[i][j])) return false;

                 if(isdigit(board[i][j])) mp[board[i][j]]++;
            }
            mp.clear();
        }
        
for(int i=0; i<board.size(); i+=3) {
    for(int j=0; j<board[0].size(); j+=3) {
               mp.clear();
               for(int p=i; p<i+3; p++ ) {
                for(int q=j; q<(j+3); q++) {
                    if(mp.count(board[p][q])) return false;
                   if(isdigit(board[p][q]))  mp[board[p][q]]++;
                }
               }

    }
}
           
    return true;

    }
};