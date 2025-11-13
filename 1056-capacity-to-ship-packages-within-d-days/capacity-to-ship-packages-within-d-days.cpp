class Solution {
public:
  bool check(vector<int> &weights,int mid,int days) {
    int i=0;
    int j=weights.size()-1;
    int cnt=1;
    int load=0;
     for(int i=0; i<weights.size(); i++) {
        if(load+ weights[i] > mid) {cnt++;
        load=weights[i];}
        else load+=weights[i];
     }

     if(cnt>days) return false;
     return true;

  }
    int shipWithinDays(vector<int>& weights, int days) {
        // sort(begin(weights),end(weights));
       
        int r=accumulate(begin(weights),end(weights),0);
        int l=*max_element(begin(weights),end(weights));
        int ans=r;
        while(l<=r) {
            int mid=l+(r-l)/2;
            if(check(weights,mid,days)) {
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