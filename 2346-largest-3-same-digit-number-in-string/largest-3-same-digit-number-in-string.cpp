class Solution {
public:
    string largestGoodInteger(string num) {
        unordered_map<int,int>  mp;
        string maxi="";

int i=0;
int j=0;
        while(j<num.size()) {
      mp[num[j]-'0']++;    if(j-i+1  >3) {
            while(j-i+1 >3) {
                mp[num[i]-'0']--;
                if(mp[num[i]-'0']==0) {
                    mp.erase(num[i]-'0');
                }
                i++;
            }
         }

 if(mp.size()==1 && j-i+1 ==3) {
                string temp =num.substr(i,j-i+1);
                maxi=max(maxi,temp);
            }
           
           

            j++;
           
        }
        return maxi;
    }
};