class Solution {
public:
bool isPalindrom(string x) {
     int i=0;
             int j=x.size()-1;
             while(i<j) {
                if(x[i]!=x[j]) {
                   
                     return false;
                }
                i++;
                j--;
             }
             return true;
}
string baseK(long long x,int k) {
    if(x==0) return "0";
     string binary="";
    while(x) {
       binary.push_back('0' + (x % k));
        x=x/k;

    }
    reverse(binary.begin(),binary.end());
    return binary;
} 
    long long kMirror(int k, int n) {
       long long cnt=0;
       long long l=1;
          while(n) {
            long long half=(l+1)/2;
        long long min_element=pow(10,half-1);
        long long max_element=pow(10,half)-1;
        for(long long i=min_element; i<=max_element; i++) {
            string first=to_string(i);
            string second=first;
            reverse(begin(second),end(second));
            string pal="";

       if(l%2==0) {
           pal=first+second;
       }
       else {
        pal=first+second.substr(1);

       }
       long long num=stoll(pal);
       if(isPalindrom(baseK(num,k))==true) {
        n--;
        cnt+=num;
        if(n==0) break;
       }
        
        }
        l++;
          }
          return cnt;
    }
};