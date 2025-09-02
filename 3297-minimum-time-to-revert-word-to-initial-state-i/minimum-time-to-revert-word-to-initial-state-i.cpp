class Solution {
public:

    bool isEqual(string word,string target) {

        for(int i=0; i<word.size(); i++) {
            if(word[i]!='*' && word[i]!=target[i]) {
                return false;
            }
        }
        return true;
    }
    int minimumTimeToInitialState(string word, int k) {

string temp=word;
int cnt=0;
         do{
          temp=temp.substr(k)+string(k,'*');
          cnt++;


         } while(!isEqual(temp,word));


      return cnt;
    }
};