class Solution {
public:
    int calculate(string s) {
        int result=0;

        int number=0;
        stack<int> st;
        int sign=1;
        for(int i=0; i<s.size(); i++) {

            if(s[i]=='-' || s[i]=='+') {
               
                result+=sign*number; 
                sign=(s[i]=='-')?-1:1;
                number=0;
            }

            else if(s[i]=='(') {
                st.push(result);
                st.push(sign);
                result=0;
                number=0;
                sign=1;
            }
            else if(s[i]==')') {
                result+=(number*sign);
                number=0;
               int stackint =st.top();
                  st.pop();
                  int lastres=st.top();
                  st.pop();
                  result*=stackint;
                  result+=lastres;

            }
        else if(s[i]!=' ') {
            number=number*10+(s[i]-'0');
          }




        }
        result+= sign*number;
        return result;
    }
};