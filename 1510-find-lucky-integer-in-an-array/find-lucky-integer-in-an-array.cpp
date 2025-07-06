class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i=0; i<arr.size(); i++) {
            mp[arr[i]]++;
        }
int maxi=INT_MIN;
        for(int i=0; i<arr.size(); i++) {
            if(mp[arr[i]]==arr[i]) {
                maxi=max(maxi,arr[i]);
            }
        }

        return (maxi==INT_MIN) ? -1:maxi;
    }
};