class Solution {
public:

   vector<int> check(string num1) {
    bool flag=true;
    int i=0;
    int a=0;
        if(num1[0]=='-') {
            flag=false;
        }
        while(i<num1.size() && !isdigit(num1[i])) {
            i++;
        }
        while(i<num1.size() && isdigit(num1[i])) {
a = a*10+(num1[i]-'0');
            i++;
        }
        if(flag==false) {
                a=a*(-1);
                flag=true;
        }
        char temp;
         while(i<num1.size() && !isdigit(num1[i])) {
            temp=num1[i];
            i++;
         }
         if(temp=='-') flag=false;
         else {
            true;
         }
         int b=0;
         while(i<num1.size() && isdigit(num1[i])) {
            b=b*10+(num1[i]-'0');
            i++;
         }
         if(flag==false) {
       b=b*(-1);
         }
       
         return {a,b};
   }
   string complexNumberMultiply(string num1, string num2) {
        vector<int> temp= check(num1);
        int a=temp[0];
        int b=temp[1];
        temp.clear();
        temp=check(num2);
        int c=temp[0];
        int d=temp[1];

        
        int one=a*c;
          int bi=-1*(b*d);
          int im=(a*d)+(b*c);
          string res=to_string(one+bi) + '+'+to_string(im)+'i';
          return res;
    }
};