class Solution {
public:
    bool isValidSerialization(string preorder) {
             int slots=1;
long long i=0;
             while(i<preorder.size()) {
                               
                if(preorder[i]==',') {
                    i++;
                    continue;
                  
                }
            slots--;
if(slots<0) return false;
                if(preorder[i]=='#') {
                      
                       i++;
                     
                }
              else if(preorder[i]!='#') {
               
                while(i<preorder.size() && preorder[i]!=',') {
               
                i++;
              
               } slots+=2;
               }
               
             }
             if(slots==0) return true;
             return false;
    }
};