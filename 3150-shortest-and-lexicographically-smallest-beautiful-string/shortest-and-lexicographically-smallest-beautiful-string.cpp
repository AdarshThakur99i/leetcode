class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
          int cntone=0;
          string mini="";
          int minlen=INT_MAX;
         int i=0;
         int j=0;
         while(j<s.size()) {
            if(s[j]=='1') cntone++;
  
            while(cntone>=k) {
                   if(cntone==k && j-i+1<minlen) {
                 string temp=s.substr(i,j-i+1);
                    mini=temp;
                    minlen=(j-i+1);
            }
            else if(cntone==k && j-i+1 ==minlen) {
                 string temp=s.substr(i,j-i+1);
                    mini=min(mini,temp);
            }
                if(s[i]=='1') cntone--;
                i++;
            }

         
            // if(j==s.size()-1) {
            //     while(cntone==k) {
            //           if(cntone==k && j-i+1<minlen) {
            //      string temp=s.substr(i,j-i+1);
            //         mini=temp;
            //         minlen=(j-i+1);
            // }
            // else if(cntone==k && j-i+1 ==minlen) {
            //      string temp=s.substr(i,j-i+1);
            //         mini=min(mini,temp);
            // }
            //         if(s[i]=='1') cntone--;
            //         i++;
            //     }
            // }
            j++;
         }
             return mini;
    }
};