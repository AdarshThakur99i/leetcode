class Solution {
public:
    void check(vector<string> &words,vector<int> &groups,int i,vector<string> &temp) {

    if(i>=words.size()) {

            
        return;
    }
       temp.push_back(words[i]);
       int j=i+1;
       
       while(j<groups.size() && groups[j]==groups[i]) {
        j++;
       }
       
        check(words,groups,j,temp);
       
       


    }
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {

       
        vector<string> ans;
        for(int i=0; i<words.size(); i++) { vector<string> temp;
        check(words,groups,i,temp);
        if(temp.size()>ans.size()) {
            ans=temp;
        }

        }

        return ans;

        
    }
};