class Solution {
public:
   bool isPalindrome(string x) {

      int start=0;
      int end=x.size()-1;

      for(int i=0; i<=end; i++) {
        if(x[i]!=x[end--])
        return false;
      }

      return true;
   }
    void check(string s,vector<string> &temp,vector<vector<string>> &ans,int i) {
             if(i==s.size()) {

                ans.push_back(temp);
                return;
             }

          for(int j=i+1; j<=s.size(); j++) {
              string x=s.substr(i,j-i);
               if(isPalindrome(x)) {
                temp.push_back(x);
                check(s,temp,ans,j);
                temp.pop_back();
               }

          }



        


    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> ans;
        check(s,temp,ans,0);

        return ans;
        
    }
};