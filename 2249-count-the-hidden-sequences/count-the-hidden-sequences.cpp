class Solution {
public:
 
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int count=0;
       int curr=0;
       int mini=0;
       int maxi=0;
       for(int &d:differences) {
        curr+=d;
        mini=min(curr,mini);
        maxi=max(maxi,curr);
   

   if((upper-maxi)-(lower-mini) +1<=0) {
    return 0;   
   }

       }
        

        return (upper-maxi)-(lower-mini)+1;
    }
}; 