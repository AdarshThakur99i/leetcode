class Solution {
public:
    int maxDiff(int num) {
        string x=to_string(num);
        string temp=x;
        if(x[0]!='9') {
            char ch=x[0];
            replace(begin(x),end(x),ch,'9');
           
        }
        else {
            int k=0;
            while(k<x.size() && x[k]=='9') {
                k++;
            }
            if(k<x.size()) {
            char ch=x[k];
            while(k<x.size()) {
                if(x[k]==ch) {
                    x[k]='9';
                }
                k++;
            }
        }}
      
    if(temp[0]!='1') {char ch=temp[0];
        for(int i=0; i<temp.size(); i++) {
          
            if(temp[i]==ch) {
                temp[i]='1';
            }
        }
    }
    else {
       
          for(int i=1; i<temp.size(); i++) {
            if(temp[i]!=temp[0] && temp[i]!='0') {
                char t=temp[i];
                replace(begin(temp),end(temp),t,'0');
                break;
            }
          
        }
    }
    

        
        int a =stoi(x);
        int b =stoi(temp);
        return a-b;
   
       
    }
};