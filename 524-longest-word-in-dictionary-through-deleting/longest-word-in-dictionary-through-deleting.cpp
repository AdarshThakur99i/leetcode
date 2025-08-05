class Solution {

public:
bool check(string &s1, string &s2) {

    int i=0;
    int j=0;
     while(i<s1.size() && j<s2.size()) {
    if(s1[i]==s2[j]) {
        i++;
        j++;
        continue;
    }
    i++;
    }

    if(j==s2.size()) {
        return true;
    }
    return false;
}
   
    string findLongestWord(string s, vector<string>& dictionary) {
        string maxi="";
             for(int i=0; i<dictionary.size(); i++) {
                if(check(s,dictionary[i])==true) {
                        if(dictionary[i].size() > maxi.size()) {
                            maxi=dictionary[i];
                        }
                        else if(dictionary[i].size()==maxi.size()) {
                            maxi=min(maxi,dictionary[i]);
                        }
                } 
             }
             return maxi;
    } 
};