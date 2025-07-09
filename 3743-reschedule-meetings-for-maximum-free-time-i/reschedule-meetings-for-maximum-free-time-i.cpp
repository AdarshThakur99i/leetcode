class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int cnt=0;
        int prev=0;
        vector<int> gap;
        
               for(int i=0; i<startTime.size(); i++) {
                int start=startTime[i];
                     
                        gap.push_back((start-prev));
                      
                     
                     prev=endTime[i];
               }
      if(endTime[endTime.size()-1] != eventTime) {
      gap.push_back(eventTime-endTime[endTime.size()-1]);
}

     int maxi=INT_MIN;
     int temp=0;
    int i=0;
    
int j=0;

    while(j<gap.size() ) {
        cnt+=gap[j];
        if(j-i > k) {
            cnt -=gap[i];
            i++;
        }
       
            maxi=max(maxi,cnt);
         j++;
    }
        return maxi==INT_MIN ? 0 : maxi;           
    }
};            