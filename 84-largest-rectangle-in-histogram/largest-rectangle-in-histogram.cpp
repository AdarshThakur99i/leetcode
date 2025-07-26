class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> leftMin(n,0);
        vector<int> rightMin(n,0);
        stack<int> st;
        for(int i=0; i<heights.size(); i++) {
               if(st.empty()) {
                st.push(i);
                leftMin[i]=-1;

               }
               else {
                     while(!st.empty() && heights[i] <=heights[st.top()]) {
                        st.pop();
                     }
                    if(!st.empty()) {
                        leftMin[i]=st.top();
                        st.push(i);
                    }
                    else {
                           leftMin[i]=-1;
                           st.push(i);
                    }

               }
        }
        while(!st.empty()) {
            st.pop();
        }
          for(int i=heights.size()-1; i>=0; i--) {
               if(st.empty()) {
                st.push(i);
                rightMin[i]=heights.size();

               }
               else {
                     while(!st.empty() && heights[i] <=heights[st.top()]) {
                        st.pop();
                     }
                    if(!st.empty()) {
                        rightMin[i]=st.top();
                        st.push(i);
                    }
                    else {
                           rightMin[i]=heights.size();
                           st.push(i);
                    }

               }
        }
        int ans=INT_MIN;
                for(int i=0; i<heights.size(); i++) {
                    int area=(rightMin[i]-leftMin[i]-1)*heights[i];
                    ans=max(ans,area);
                }

                return ans;
    }      
};