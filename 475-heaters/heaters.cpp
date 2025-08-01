class Solution {
public:
    bool check(vector<int> &houses,vector<int>& heaters,int radius) {
int i=0;
int j=0;
           while(i<houses.size() && j<heaters.size()) {
                if(abs(heaters[j]-houses[i]) > radius) {
           j++;
                }
                else {
                    i++;
                }
           }

           if(i==houses.size()) return true;
           return false;
    } 
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(begin(houses),end(houses));
        sort(begin(heaters),end(heaters));
        if(houses==heaters) {
return 0;
        }
        long long l=0;
        long long r=1e9;
       
        int ans=-1;
        while(l<=r) {
            int mid=l+(r-l)/2;
            if(check(houses,heaters,mid)) {
                ans=mid;
                r=mid-1;
            }
            else {
                 l=mid+1;
            }
        }
        return ans;
    }
};