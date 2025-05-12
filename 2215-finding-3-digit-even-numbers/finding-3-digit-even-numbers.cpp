class Solution {
public:

  
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        
      unordered_map<int,int> mp;
      for(int i=0; i<digits.size(); i++) {
     mp[digits[i]]++;


      }
      unordered_map<int,int> p;
      p=mp;
        
for(int i=100; i<1000; i++) {
    mp=p;
    if(i%2!=0) continue;
int temp=i;
    while(temp!=0)  {
        int x=temp%10;
       
        if(mp[x]!=0) {
            mp[x]--;
        }
        else {
            break;
        } temp=temp/10;
    }
    if(temp==0) {
ans.push_back(i);
    }
}



      return ans;
    }
};