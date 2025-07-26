class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
             vector<vector<int>> conflict(n+1);
             for(auto it: conflictingPairs) {
              int maxi=max(it[0],it[1]);
              int mini=min(it[0],it[1]);
              conflict[maxi].push_back(mini);
             }
long long valid=0;
             vector<long long> extra(n+1,0);
             long long maxi=0;
             long long secondMaxi=0;
             for(int end=1; end<=n; end++) {
                for(auto it: conflict[end]) {
                     if(it>=maxi) {
                        secondMaxi=maxi;
                        maxi=it;
                     }  
                     else if(it>secondMaxi) {
                        secondMaxi=it;
                     }
                }
                valid+=end-maxi;
                extra[maxi] += maxi-secondMaxi;
             }
             return valid + *max_element(begin(extra),end(extra));

    }
};

//1 2 3 4 5 6   1,2,3,4,5,6,12,23,34,45,56,123,234,345,456,1234,2345,3456,12345,23456
//1,2,3,4,5,6,12,23,45,56,123