class Solution {
public:
    int totalFruit(vector<int>& fruits) {
         unordered_map<int,int> st;
         int i=0;
         int j=0;
         int maxi=INT_MIN;
         while(j<fruits.size()) {
            st[fruits[j]]++;
              
                if(st.size()>2) {
                    while(i<fruits.size() && st.size() > 2) {
                        st[fruits[i]]--;
                        if(st[fruits[i]]==0) {
                            st.erase(fruits[i]);
                        }
                        i++;
                    }
                }
                
             
maxi=max(maxi,j-i+1);
           j++;
         }
         return maxi;
    }
};