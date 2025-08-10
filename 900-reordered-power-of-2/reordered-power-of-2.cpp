class Solution {
public:
    bool reorderedPowerOf2(int n) {
    string x=to_string(n);
    sort(begin(x),end(x));
       if(n==1) return true;
        long long num=2;
        while(true) {
            
           string temp=to_string(num);
           sort(begin(temp),end(temp));
           if(temp==x) return true;

           num=num*2;
           if(temp.size()>x.size()) break;
           
        }
        
         return false;
    }
};