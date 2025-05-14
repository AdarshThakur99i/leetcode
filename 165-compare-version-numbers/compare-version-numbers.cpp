class Solution {
public:
    int compareVersion(string version1, string version2) {
       int idx1=0;
       vector<string> temp1;
       for(int i=0; i<version1.size(); i++) {
           if(version1[i]=='.') {
            string temp=version1.substr(idx1,i-idx1);

            idx1=i+1;
            temp1.push_back(temp);

           }
        
       }
      string x=version1.substr(idx1,version1.size()-idx1);
      temp1.push_back(x);
      idx1=0;

        vector<string> temp2;
       for(int i=0; i<version2.size(); i++) {
           if(version2[i]=='.') {
            string temp=version2.substr(idx1,i-idx1);

            idx1=i+1;
            temp2.push_back(temp);
           

           }
        
       }
       x=version2.substr(idx1,version2.size()-idx1);
       temp2.push_back(x);

   

       int i=0;
       int j=0;
       while(i<temp1.size() && j<temp2.size()) {

           int one=stoi(temp1[i]);
           int two=stoi(temp2[j]);

           if(one>two) {
            return 1;
           }
           else if(two>one) {
            return -1;
           }

        i++;
        j++;
       }

       if(i<temp1.size()) {
          while(i<temp1.size() && stoi(temp1[i])==0) {
            i++;
          }
          if(i<temp1.size()) return 1;
       }
       else if(j<temp2.size()) {
       while(j<temp2.size() && stoi(temp2[j])==0) {
            j++;
          }
          if(j<temp2.size()) return -1;
       }



return 0;
    }
};