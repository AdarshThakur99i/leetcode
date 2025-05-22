class Solution {
public:
    int calculate(string s) {
       stack<int> st;
       bool check=false;
       int number=0;
       char operation='+';
       int result=0;
       for(int i=0; i<s.size(); i++) {
         if(isdigit(s[i])) {
            number=number*10+(s[i]-'0');
         }
         if(!isdigit(s[i]) && s[i]!= ' ' || i==s.size()-1) {
        
        if(operation=='+') {
            st.push(number);
            number=0;
          
            
        }
        else if(operation=='-') {
            st.push(-number);
            number=0;
           
        
        }
        else if(operation=='*') {
            int x=st.top();
            st.pop();
            st.push(number*x);



        }
        else if(operation=='/') {
       int x=st.top();
            st.pop();
            st.push(x/number);

        }      
        operation=s[i];
        number=0;
       }}
       while(!st.empty()) {
        result+=st.top();
        st.pop();
       }

       return result;
    }
};