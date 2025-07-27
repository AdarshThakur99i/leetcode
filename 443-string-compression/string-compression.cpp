class Solution {
public:
    int compress(vector<char>& chars) {
        string res="";
        int i=0;
       while(i<chars.size()) {
            res.push_back(chars[i]);
            int temp=0;
            while(i<chars.size() && chars[i]==res.back()) {
                i++;
                temp++;
            }
            i--;
            if(temp>1) res+=to_string(temp);
         i++;
        }
      int j=0;
       
        for( j=0; j<res.size(); j++) {
             chars[j]=res[j];
        }
        int rem=chars.size()-j;
        while(rem>0) {
            chars.pop_back();
            rem--;
        }
        return res.size();
    }
};