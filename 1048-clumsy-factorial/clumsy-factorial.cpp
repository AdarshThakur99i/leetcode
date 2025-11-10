class Solution {
public:
    int clumsy(int n) {
        int temp=0;
        int result=0;
        stack<int> st;
        st.push(n);
        n--;
     
        while(n>0) {
            temp=temp%4;
          

                if(temp==2) st.push(n);
                else if(temp==3) st.push(-n);
           else {    if(!st.empty()) {   int x=st.top();
                st.pop();
                   if(temp==0) {
                      int res=x*n;
                    st.push(res);
                   }
                   else if(temp==1) {
                    int res=x/n;
                    st.push(res);
                   }
            } }
            temp++;
            n--;

        }
        while(!st.empty()) {
result += st.top();
st.pop();
        }
      
        return result;
    }
};