class Solution {
public:
    string smallestPalindrome(string s) {
         map<char,int> mp;
         for(auto it: s) {
             mp[it]++;
         }
        
        string x="";
        string x2="";
        string mid="";
        
        for(auto &it: mp) {
            if(it.second%2 !=0) {
                mid+=it.first;
                it.second--;
                break;
            }

        }

        for(auto &it:mp) {

            while(it.second>0) {
           x+=it.first;
           it.second--;

           x2+=it.first;
           it.second--;
            }
        }







        reverse(x2.begin(),x2.end());
        
    return x+mid+x2;
        
        
        
        
    }
};