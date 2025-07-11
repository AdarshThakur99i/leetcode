class Solution {
public:
int check(string s,int start,int end,int k) {
          if(end - start <k) return 0;
          
          vector<int> freq(26,0);
          for(int i=start; i<end; i++) {
            freq[s[i]-'a']++;
          }
          for(int i=start; i<end; i++) {
            if(freq[s[i]-'a'] < k) {

                int next=i+1;
                while(next < end && freq[s[next]-'a'] < k) {
                    next++;
                }


                int left=check(s,start,i,k);
                int right=check(s,next,end,k);
                return max(left,right);
            }
          }
          return end-start;
}
    int longestSubstring(string s, int k) {
        return check(s,0,s.size(),k);
         

        
    }
};