class Solution {
public:
 void check(vector<int> &nums,vector<int>& minRight,vector<int>& minLeft) {

    stack<int> st;
   
    for(int i=0; i<nums.size(); i++) {
        if(st.empty()) {
            minLeft[i]=-1;
            st.push(i);
        }
        else {
            while(!st.empty() && nums[i]<=nums[st.top()]) {
                st.pop();
            }
            if(!st.empty()) {
                minLeft[i]=st.top();
                st.push(i);
            }
            else {
                minLeft[i]=-1;
                st.push(i);
            }
        }
    }
 while(!st.empty()) {
    st.pop();
 }
        for(int i=nums.size()-1; i>=0; i--) {
        if(st.empty()) {
            minRight[i]=nums.size();
            st.push(i);
        }
        else {
            while(!st.empty() && nums[i]<=nums[st.top()]) {
                st.pop();
            }
            if(!st.empty()) {
                minRight[i]=st.top();
                st.push(i);
            }
            else {
                minRight[i]=nums.size();
                st.push(i);
            }
        }
    }
   }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> nums(matrix[0].size(),0);
        int res=INT_MIN;
        for(int i=0; i<matrix.size(); i++) {
            vector<int> minRight(matrix[0].size(),0);
            vector<int> minLeft(matrix[0].size(),0);
            for(int j=0; j<matrix[i].size(); j++) {
             if(matrix[i][j]=='0') nums[j]=0;
             else {
                nums[j] +=1;
             }
            }
            check(nums,minRight,minLeft);
            for(int i=0; i<nums.size(); i++) {
                int area=((minRight[i]-minLeft[i]-1))*nums[i];
                res=max(res,area);
            }
        }
        return res;
    }
}; 