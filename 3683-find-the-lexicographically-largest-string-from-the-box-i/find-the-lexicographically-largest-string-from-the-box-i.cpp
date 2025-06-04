class Solution {
public:
 
    string answerString(string word, int numFriends) {
       
        if(numFriends==1) return word;
        string x="";
      
        for(int i=0; i<word.size(); i++) {
             x=max(x,word.substr(i,word.length()-numFriends+1));
              
            }
        
        

        return x;

      
        
    }
};