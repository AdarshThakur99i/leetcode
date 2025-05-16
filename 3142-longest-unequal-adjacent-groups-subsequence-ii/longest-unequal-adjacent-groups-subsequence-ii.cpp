class Solution {
public:

  bool hamming(string a,string b) {
    if(a.size()!=b.size()) return false;

    int temp=0;
    for(int i=0; i<a.size(); i++) {
        if(a[i]!=b[i]) {
            temp++;
        }
        if(temp>1) return false;
    }

    if(temp==1) return true;
    return false;
  }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {

       vector<int> dp(words.size(),1);
       vector<int> prevIdx(words.size(),-1);
       int maxi=INT_MIN;
       int maxidx=0;

       for(int i=0; i<words.size(); i++) {
        for(int j=0; j<i; j++) {
            if(groups[i]!=groups[j] && hamming(words[i],words[j])) {
                 if(dp[j]+1 > dp[i]) {
                    dp[i]=dp[j]+1;
                    prevIdx[i]=j;

                 }
                 if(dp[i]>maxi) {
                    maxi=dp[i];
                    maxidx=i;
                 }


            }

        }
       }

       vector<string> result;
       while(maxidx!=-1) {

        result.push_back(words[maxidx]);
        maxidx=prevIdx[maxidx];
       }
        reverse(result.begin(),result.end());
       return result;

        
    }
};