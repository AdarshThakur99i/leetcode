class Solution {
public:
    int candy(vector<int>& ratings) {
         vector<int> suff(ratings.size(),1);
      
         for(int i=ratings.size()-2; i>=0; i--)  {
            if(ratings[i]>ratings[i+1]) {
                suff[i]=suff[i+1]+1;
            }
            
         }

         vector<int> prefix(ratings.size(),1);

      
          for(int i=1; i<prefix.size(); i++) {
                     if(ratings[i-1]<ratings[i]) {
                        prefix[i]=prefix[i-1]+1;
                     }
                   
          }      
          int count=0;
          for(int i=0; i<ratings.size(); i++) {
                  count+=max(prefix[i],suff[i]);
          }

          return count;

    }
};