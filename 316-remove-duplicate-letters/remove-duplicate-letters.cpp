class Solution {
public:
    string removeDuplicateLetters(string s) {
      vector<int> lastidx(26,0);
      stack<char> st;
      for(int i=0; i<s.size(); i++) {
        lastidx[s[i]-'a']=i;
      }
      vector<bool> used(26,false);
string res="";
      for(int i=0; i<s.size(); i++) {
        if(used[s[i]-'a']) continue;
        
            while(!st.empty() && lastidx[st.top()-'a'] > i && s[i]<st.top()) {
                used[st.top()-'a']=false;
                  st.pop();
            }
            st.push(s[i]);   used[s[i]-'a']=true;
        }
 
       while(!st.empty()) {
        res+=st.top();
        st.pop();
       }
       reverse(begin(res),end(res));
          
   

       return res;
    }
}; 