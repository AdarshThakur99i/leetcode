class Solution {
public:
    int maxProduct(vector<string>& word) {
         int maxi=INT_MIN;
       
          vector<int> mask(word.size(),0);
          for(int i=0; i<word.size(); i++) {
            int bitmask=0;
            for(auto c : word[i]) {
                bitmask |=  (1<< (c-'a'));
            }
            mask[i]=bitmask;
          }
         for(int i=0; i<word.size(); i++) {
            
            for(int j=i+1; j<word.size(); j++) {
                     if((mask[i]&mask[j])==0) {
                        int a=word[i].size();
                        int b=word[j].size();
                        maxi=max(maxi,a*b);
                     }
                }
            }
            return (maxi==INT_MIN)?0 :maxi;
         
    }
};