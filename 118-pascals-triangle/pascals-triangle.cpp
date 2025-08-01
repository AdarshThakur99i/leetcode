class Solution {
public:
    // vector<int> check(vector<int> &ans,int i,int numRows) {
    //    if(i==ans.back().size()) {
    //     return ans;
    //    }
    //     if(i==0) temp.push_back()

        
    // }
    vector<vector<int>> generate(int numRows) {

            vector<vector<int>> ans;
             vector<int> prev;
            prev.push_back(1); ans.push_back(prev);
            if(numRows==1) return ans;
            ans.push_back({1,1});
            prev={1,1};
            if(numRows==2) return ans;
            for(int i=0; i<numRows-2; i++) {
                vector<int> temp;
              
                for(int i=0; i<prev.size(); i++) {
                    if(i==0) temp.push_back(prev[i]);
                    else if(i==prev.size()-1) {
                       if(i-1>=0) { temp.push_back(prev[i]+prev[i-1]);}
                        temp.push_back(prev[i]);
                    }
                    else {
                        temp.push_back(prev[i]+prev[i-1]);
                    }
                }
                ans.push_back(temp);
                prev=temp;
            }
            
            return ans;
    }
};