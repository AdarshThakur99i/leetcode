class Solution {
public:
    string decodeString(string s) {
        
      stack<string> st;
      stack<int> count;

        int i=0;
        int flag=0;
      string ans="";
        string res="";
        while(i<s.size()) {
         if(isdigit(s[i])) {
            int num=0;
           while(isdigit(s[i])) {
            num=num*10 + (s[i]-'0');
            i++;
         }
         count.push(num);}
       else  if(s[i]=='[') {
              st.push(res);
              res="";
              i++;
    }
   

  else   if(s[i]==']') {
    string temp=res;
          res=st.top();
         st.pop();
         int numb= count.top();
         
         count.pop();
            while(numb>0) {
             res+=temp;
               numb--;
            }
            i++;
    }
    else {
        res+=s[i];
        i++;
    }
    
        }

        return res;  
    }
};