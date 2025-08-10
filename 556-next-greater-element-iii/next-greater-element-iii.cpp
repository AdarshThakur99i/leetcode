class Solution {
public:
    int nextGreaterElement(int n) {
      string x=to_string(n);
      
    
      int i=x.size()-2;
      while(i>=0 && x[i]>=x[i+1]) i--;
       
        if(i<0) return -1;

    int j=x.size()-1;
    while(j>i && x[j]<=x[i]) j--;
     swap(x[j],x[i]);
     reverse(x.begin()+i+1,x.end());
       return stoll(x)>INT_MAX ? -1:stoll(x);
    }
};
//3234234