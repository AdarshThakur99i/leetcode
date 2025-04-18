class Solution {
public:
     string check(int n,string temp,string orig) {
       if(n==0) return temp;
        int i=0;
       
        while(i<temp.size()) {
             int num=1;
         
             while(i+1<temp.size() && temp[i]==temp[i+1]) {
                i++;
                num++;
             }
            
            orig+=to_string(num)+temp[i];
            i++;
        }


         
        
        string s="";

       return check(n-1,orig,s);
       

     }
    
    string countAndSay(int n) {
        string say="";
        if(n==1) return "1";
       
        return check(n-1,"1",say);
    }

               
    
};