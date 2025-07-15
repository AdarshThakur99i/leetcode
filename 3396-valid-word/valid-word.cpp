class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3) return false;
        bool isVowel=false;
        bool isConso=false;
        for(int i=0; i<word.size(); i++) {
            if((word[i]>='a' && word[i]<='z') || (word[i]>='A' && word[i]<='Z') || isdigit(word[i])) {
                if(word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u' || word[i]=='A' || word[i]=='E' || word[i]=='I' || word[i]=='O' || word[i]=='U') {
                    isVowel=true;
                }
                else {
                     if(!isdigit(word[i])) {
                       isConso=true;
                     }
                }
            }
            else {
                return false;
            }
        }
        if(isVowel==true && isConso==true) {
            return true;
        }

        return false;
    }
};