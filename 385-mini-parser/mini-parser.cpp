/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
         stack<NestedInteger> st;
         if(s[0]!= '[') return stoi(s);
         int num=0;
         bool hasNum=false;
         bool neg=false;
          for(int i=0; i<s.size(); i++) {
                char ch=s[i];
                if(ch=='-') {
                    neg=true;
                } else if(isdigit(ch)) {
                   num=num*10+(ch-'0');
                   hasNum=true;
                }
                else if(ch=='[') {
                    st.push(NestedInteger());
                }
                else if(ch==',' || ch==']') {
                        if(hasNum) {
                            if(neg) num=-num;
                        
                        st.top().add(NestedInteger(num));
                        num=0;
                        hasNum=false;
                        neg=false;
                }
                     if(ch==']' && st.size()>1) {
          NestedInteger ni=st.top();
                    st.pop();
                    st.top().add(ni);
                     }
                }
               
          }  
return st.top();
    }
};