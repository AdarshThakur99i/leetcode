class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
    
        unordered_set<int> prev;
        unordered_set<int> res;
        for(int i=0; i<arr.size(); i++) {    unordered_set<int> curr;
            for(auto &it: prev) {
                  curr.insert(arr[i] | it);
                  res.insert(arr[i] | it);
            }
            curr.insert(arr[i]);
            res.insert(arr[i]);
            prev=curr;
        }
        return res.size();
    }
};