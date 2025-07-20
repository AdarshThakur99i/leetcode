class Solution {
public:
    const int MOD=1e9+7;
    long long countTrapezoids(vector<vector<int>>& points) {
     unordered_map<long long,long long> mp;
     for(int i=0; i<points.size(); i++) {
        mp[points[i][1]]++;
     }
    vector<long long> combinations;
    for(auto it: mp) {
        if(it.second >=2) {
            combinations.push_back((it.second)*(it.second-1)/2);
        }
    }
    if(combinations.size()<2)  return 0;
    long long ans=0;
    long long pre_sum=0;
    for(int i=0; i<combinations.size(); i++) {
        ans+= (pre_sum)*combinations[i];
        pre_sum+=combinations[i];
    }

    return (ans%MOD);
    }
};