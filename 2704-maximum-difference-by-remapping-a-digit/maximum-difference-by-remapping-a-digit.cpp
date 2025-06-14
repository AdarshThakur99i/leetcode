class Solution {
public:
    int minMaxDifference(int num) {
        string x=to_string(num);
        string temp=x;
        char p=x[0];
       if(x[0]!='9') {
        for(int i=0; i<x.size(); i++) {
             if(x[i]==p) {
               x[i]='9';
             }
        }}
        else {
            int i=0;
            while(i<x.size() && x[i]=='9') {
                i++;
            }
         p=x[i];
         while(i<x.size()) {
            if(x[i]==p) x[i]='9';
            i++;
         }
        }
        int a=stoi(x);
        
        char j=temp[0];
       for(int i=0; i<temp.size(); i++) {   
        if(temp[i]==j) temp[i]='0';
       }
        
      int b=stoi(temp);


      return a-b;
    }
};