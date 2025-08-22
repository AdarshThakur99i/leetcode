class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(begin(tasks),end(tasks));
        sort(begin(processorTime),end(processorTime));
        int i=tasks.size()-1;
        long long maxi=LLONG_MIN;
        int j=0;
        while(i>=0 && j<processorTime.size()) {
            long long a=tasks[i];
            long long b=tasks[i-1];
            long long c=tasks[i-2];
            long long d=tasks[i-3];
            long long strt=processorTime[j];
           long long maxc=max({strt+a,strt+b,strt+c,strt+d});
           maxi=max(maxi,maxc);
            i-=4;
            j++;

        }
        return maxi;
    }
};