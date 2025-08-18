class Solution {
public:

    int minimumOperations(string num) {
        
        vector<string> targets={"00","25","50","75"};
int mini=num.size();
        for(auto &t: targets) {
int j=1;
int deletion=0;

            for(int i=num.size()-1; i>=0; i--) {
                if(num[i]==t[j]) {
                    j--;
                
                if(j<0) {
mini=min(mini,deletion);
break;
                }}
                else {
                    deletion++;
                }


            }
        } 

        if(num.find('0') != string::npos) {
            int x=num.size()-1;
               mini=min(mini,x);
        }

        return mini;
    }
};