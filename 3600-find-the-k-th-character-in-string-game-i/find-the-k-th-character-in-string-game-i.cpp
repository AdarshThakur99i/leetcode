class Solution {
public:
    char kthCharacter(int k) {
         string res="a";
        
         while((int)res.size()<k) {
            string x="";
             for(int i=0; i<res.size(); i++) {
                if(res[i]=='z') {
                    x+='a';
                }
                else {
                x+=(res[i]+1);}
             }
             res+=x;
             if(res.size()>k) break;

            
         }

         return res[k-1];
    }
}; 