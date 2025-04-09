class Solution {
public:

bool isValid(string x) {

    if(x.size()>1 && x[0]=='0') return false;

    int in=stoi(x);

    if(in>255) return false;

    return true;
}
    void check(string s,vector<string> &ans,string temp1,int i,int k) {

     if(k>4) return;
            if(i==s.size() && k==4) {
         temp1.pop_back();
                ans.push_back(temp1);
                return;

            }if(i>=s.size()) return;
             
        
              check(s,ans,temp1+s[i]+'.',i+1,k+1);

           
              string x=s.substr(i,2);
            if(i+1<s.size()&& isValid(x)) {
              check(s,ans,temp1+x+'.',i+2,k+1);
            }
             
              string x3=s.substr(i,3);
            if(i+2<s.size() && isValid(x3)) {
              check(s,ans,temp1+x3+'.',i+3,k+1);}
              
               





              

            



    }
    vector<string> restoreIpAddresses(string s) {

       string temp1="";
       string temp2="";
        vector<string> ans;
        int k=0;
        check(s,ans,temp1,0,k);

        return ans;
    }
};