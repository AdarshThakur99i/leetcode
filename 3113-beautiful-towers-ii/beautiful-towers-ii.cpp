class Solution {
public:
   void find(vector<long long>& prefix,vector<int> &heights) {
              stack<pair<long long,int>> st;
            
              for(int i=0; i<heights.size(); i++) {
                if(i==0) {
                    prefix[0]=heights[0];
                    st.push({heights[0],0});
                }
                    while(!st.empty() && heights[i] < st.top().first) {
                                   st.pop();       
                    }

                    if(st.empty()) {
                        prefix[i]=1LL*(i+1)*heights[i];
                    }
                    else {
                        int dis=(i-st.top().second);
                        prefix[i]=prefix[st.top().second]+(1LL*dis*heights[i]);
                    }
                    st.push({heights[i],i});
              }
                  
   }
    long long maximumSumOfHeights(vector<int>& heights) {
               vector<long long> prefix(heights.size(),-1);
                vector<long long> suffix(heights.size(),-1);
               find(prefix,heights);
               reverse(begin(heights),end(heights));
               find(suffix,heights);
               reverse(begin(heights),end(heights));
                   reverse(begin(suffix),end(suffix));
long long maxi=LLONG_MIN;
               for(int i=0; i<heights.size(); i++) {
                long long x=prefix[i]+suffix[i]-heights[i];
                  maxi=max(maxi,x);
               }
                 return maxi;
    }
};
//0 1 2 3 4 5