class Solution {
public:
    string fractionAddition(string expression) {
      int num=0;
      int deno=1;
   string ans="";
   int i=0;
       while(i<expression.size()) {
       int sign=1;  
        if(expression[i]=='+' || expression[i]=='-') {
        if(expression[i]=='-') {
            sign=-1;
           
        } i++;
       }
       int currnum=0;
       while(i<expression.size() && isdigit(expression[i])) {
           currnum= (currnum*10) + (expression[i]-'0');
           i++;
       }
       currnum=currnum*sign;
       i++;
       int currdeno=0;
       while(i<expression.size() && isdigit(expression[i])) {
            currdeno=currdeno*10+(expression[i]-'0');
        i++; 
       }
       int finalNum= (num*currdeno + (currnum*deno));
       int finalDeno=deno*currdeno;
       int gcD=gcd(finalNum,finalDeno);
        finalNum= finalNum/gcD;
        finalDeno=finalDeno/gcD;
       if(finalDeno<0) {
         finalNum=-finalNum;
        finalDeno=-finalDeno;
       }
    num=finalNum;
    deno=finalDeno;
        
        }
       ans+=to_string(num)+'/'+to_string(deno);
        return ans;
    }
};